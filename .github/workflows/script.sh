#!/usr/bin/env bash
set -euo pipefail

for tool in jq curl git; do
    command -v "$tool" >/dev/null || { echo "Missing required tool: $tool" >&2; exit 1; }
done

cd "$(git rev-parse --show-toplevel)"

COMMIT_HASH=$(git rev-parse "${SUBMISSION_COMMIT:-HEAD}")
COMMIT_SHORT=$(git rev-parse --short "$COMMIT_HASH")
COMMIT_SUBJECT=$(git log -1 --format=%s "$COMMIT_HASH")
COMMIT_TIME=$(TZ=Asia/Kolkata git log -1 --format=%cd --date=format:'%Y-%m-%d %H:%M:%S' "$COMMIT_HASH")

if [[ ! "$COMMIT_SUBJECT" =~ \[([0-9]+)\] ]]; then
    echo 'No submission problem number in commit message; skipping.'
    exit 0
fi

PROBLEM_NUMBER=${BASH_REMATCH[1]}
TIME_BEATS='N/A'
MEMORY_BEATS='N/A'

if [[ "$COMMIT_SUBJECT" =~ Time\ Beats:\ ([-0-9.]+%) ]]; then TIME_BEATS=${BASH_REMATCH[1]}; fi
if [[ "$COMMIT_SUBJECT" =~ Memory\ Beats:\ ([-0-9.]+%) ]]; then MEMORY_BEATS=${BASH_REMATCH[1]}; fi

# A daily source takes priority if both copies were included in the commit.
FILES=()
DAILY_FILES=()

while IFS= read -r -d '' path; do
    if [[ "${path##*/}" =~ ^${PROBLEM_NUMBER}-.+\.(cpp|java|py|js|ts|sql|sh)$ ]]; then
        FILES+=("$path")
        if [[ "$path" =~ ^DCP-[0-9]{2}-[0-9]{2}/ ]]; then DAILY_FILES+=("$path"); fi
    fi
done < <(git diff-tree --root --no-commit-id --name-only --diff-filter=AM -r -z "$COMMIT_HASH")

if ((${#FILES[@]} == 0)); then
    echo "No numbered solution file for problem $PROBLEM_NUMBER; skipping."
    exit 0
fi

if ((${#DAILY_FILES[@]})); then FILES=("${DAILY_FILES[@]}"); fi

mkdir -p SQL SHELL
# Git needs placeholders to retain empty folders.
for ((start=1; start<=4200; start+=100)); do
    printf -v folder '%04d-%04d' "$start" "$((start+99))"
    mkdir -p "$folder"
    touch "$folder/.gitkeep"
done
touch SQL/.gitkeep SHELL/.gitkeep

ENTRIES=$(mktemp)
CODE_TMP=$(mktemp)
README_TMP=$(mktemp)

trap 'rm -f "$ENTRIES" "$CODE_TMP" "$README_TMP"' EXIT

for FILE in "${FILES[@]}"; do
    BASENAME=${FILE##*/}
    EXT=${BASENAME##*.}
    TITLE_PART=${BASENAME#"$PROBLEM_NUMBER"-}
    TITLE_PART=${TITLE_PART%.*}
    SLUG=$(printf '%s' "$TITLE_PART" | tr '[:upper:]' '[:lower:]' | sed -E "s/['()]//g; s/[^a-z0-9]+/-/g; s/^-|-$//g")
    PROBLEM_TITLE=${TITLE_PART//-/ }
    DIFFICULTY=Unknown
    PROBLEM_SLUG=$SLUG
    # /select returns questionFrontendId (the public problem number), not questionId.
    DATA=$(curl -fsSL --connect-timeout 15 --max-time 90 --retry 2 --get \
        --data-urlencode "titleSlug=$SLUG" \
        https://alfa-leetcode-api.onrender.com/select || true)
    
    if META=$(printf '%s' "$DATA" | jq -er --arg id "$PROBLEM_NUMBER" '
        select((.questionFrontendId | tostring) == $id)
        | [.questionTitle, .titleSlug, .difficulty]
        | select(all(.[]; type == "string" and length > 0)) | @tsv' 2>/dev/null); then
        IFS=$'\t' read -r PROBLEM_TITLE PROBLEM_SLUG DIFFICULTY <<< "$META"
    else
        echo "Warning: metadata unavailable or mismatched for #$PROBLEM_NUMBER; using filename." >&2
    fi
    
    POTD=''
    
    if [[ "$FILE" =~ ^DCP-[0-9]{2}-[0-9]{2}/ ]]; then POTD=' 🌟 POTD'; fi

    DB=''

    if [[ "$EXT" == sql ]]; then DB=' 🗄️'; fi

    case "$EXT" in
        sql) DEST="SQL/$BASENAME" ;;
        sh) DEST="SHELL/$BASENAME" ;;
        *)
            NUMBER=$((10#$PROBLEM_NUMBER))
            START=$(((NUMBER-1)/100*100+1))
            printf -v RANGE '%04d-%04d' "$START" "$((START+99))"
            DEST="$RANGE/$BASENAME"
            if ((NUMBER < 1)) || [[ ! -d "${DEST%/*}" ]]; then
                echo "Create a range folder for problem $PROBLEM_NUMBER before processing." >&2
                exit 1
            fi ;;
    esac

    git show "$COMMIT_HASH:$FILE" > "$CODE_TMP"
    # Preserve the DCP source; root submissions move into their destination.
    if [[ -f "$DEST" ]] && ! cmp -s "$CODE_TMP" "$DEST"; then
        ALTERNATIVE="${DEST%.*}-Alternative.$EXT"
        VERSION=2
        while [[ -e "$ALTERNATIVE" ]] && ! cmp -s "$DEST" "$ALTERNATIVE"; do
            ALTERNATIVE="${DEST%.*}-Alternative-$VERSION.$EXT"
            VERSION=$((VERSION+1))
        done
        cp "$DEST" "$ALTERNATIVE"
    fi

    cp "$CODE_TMP" "$DEST"

    if [[ "$FILE" != "$DEST" && "$FILE" != */* ]]; then rm -f -- "$FILE"; fi

    # Rerunning a commit should organise files without duplicating its README entry.
    if grep -Fq "<!-- submission:$COMMIT_HASH:$EXT -->" README.md; then continue; fi
    {
        printf '\n<!-- submission:%s:%s -->\n<details>\n' "$COMMIT_HASH" "$EXT"
        printf '<summary><h3>%s-%s%s%s</h3></summary>\n\n' "$PROBLEM_NUMBER" "$PROBLEM_TITLE" "$POTD" "$DB"
        printf '`%s` `Time Beats: %s` `Memory Beats: %s` `Commit:%s` `Solved At: %s` <code><a href="https://leetcode.com/problems/%s/description/" target="_blank">LINK</a></code>\n\n' \
            "$DIFFICULTY" "$TIME_BEATS" "$MEMORY_BEATS" "$COMMIT_SHORT" "$COMMIT_TIME" "$PROBLEM_SLUG"
        printf '```%s\n' "$EXT"
        cat "$CODE_TMP"
        printf '\n```\n\n</details>\n\n'
    } >> "$ENTRIES"
done

if ! grep -qF '<!-- SUBMISSIONS -->' README.md; then
    echo 'README submission marker is missing.' >&2
    exit 1
fi

awk -v entries="$ENTRIES" '
    { print }
    /<!-- SUBMISSIONS -->/ { while ((getline line < entries) > 0) print line; close(entries) }
' README.md > "$README_TMP"

cat "$README_TMP" > README.md

if [[ -n "${GITHUB_ENV:-}" ]]; then
    # Keep the submission message, without the extension's branding suffix.
    SUBMISSION_MESSAGE=$(printf '%s' "$COMMIT_SUBJECT" | sed -E 's/[[:space:]]*-[[:space:]]*LeetPush[[:space:]]*$//; s/LeetPush//g; s/[[:space:]]+$//')
    printf 'LEETCODE_COMMIT_MESSAGE=%s\n' "$SUBMISSION_MESSAGE" >> "$GITHUB_ENV"
    printf 'LEETCODE_PROBLEM_NUMBER=%s\nLEETCODE_PROBLEM_TITLE=%s\nLEETCODE_COMMIT_DATE=%s\n' \
        "$PROBLEM_NUMBER" "$PROBLEM_TITLE" "${COMMIT_TIME:0:10}" >> "$GITHUB_ENV"
fi
