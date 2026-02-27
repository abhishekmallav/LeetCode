#!/usr/bin/env bash
set -e

# Check for required tools
if ! command -v jq &> /dev/null; then
    echo "Error: jq is not installed. Please install jq first." >&2
    exit 1
fi

if ! command -v curl &> /dev/null; then
    echo "Error: curl is not installed. Please install curl first." >&2
    exit 1
fi

RAW_COMMIT=$(git log -1 --pretty=format:"%h - %s")
COMMIT_TIME=$(TZ=Asia/Kolkata git log -1 --pretty=format:"%cd" --date=format:"%Y-%m-%d %H:%M:%S")
COMMIT_HASH=$(echo "$RAW_COMMIT" | awk '{print $1}')

PROBLEM_NUMBER=$(echo "$RAW_COMMIT" | grep -oE '\[[0-9]+\]' | tr -d '[]')

# Check if this is a LeetCode commit (has problem number)
if [[ -z "$PROBLEM_NUMBER" ]]; then
    echo "Info: This commit doesn't contain a LeetCode problem number. Skipping." >&2
    exit 0
fi

TIME_BEATS=$(echo "$RAW_COMMIT" \
  | grep -oE 'Time Beats: [0-9.]+%' \
  | grep -oE '[0-9.]+%')

MEMORY_BEATS=$(echo "$RAW_COMMIT" \
  | grep -oE 'Memory Beats: [0-9.]+%' \
  | grep -oE '[0-9.]+%')

# Validate performance metrics
if [[ -z "$TIME_BEATS" ]] || [[ -z "$MEMORY_BEATS" ]]; then
    echo "Error: Could not extract performance metrics from commit message." >&2
    echo "Expected format: [ID] [Time Beats: X.XX%] [Memory Beats: X.XX%]" >&2
    exit 1
fi

# Fetch LeetCode problems data
PROBLEM_DATA=$(curl -s https://leetcode.com/api/problems/all/)

if [[ -z "$PROBLEM_DATA" ]] || [[ "$PROBLEM_DATA" == "null" ]]; then
    echo "Error: Failed to fetch LeetCode problems data." >&2
    exit 1
fi

PROBLEM_TITLE=$(echo "$PROBLEM_DATA" | jq -r --arg id "$PROBLEM_NUMBER" '
.stat_status_pairs[]
| select((.stat.frontend_question_id|tostring) == $id)
| .stat.question__title
')

PROBLEM_SLUG=$(echo "$PROBLEM_DATA" | jq -r --arg id "$PROBLEM_NUMBER" '
.stat_status_pairs[]
| select((.stat.frontend_question_id|tostring) == $id)
| .stat.question__title_slug
')

DIFFICULTY=$(echo "$PROBLEM_DATA" | jq -r --arg id "$PROBLEM_NUMBER" '
.stat_status_pairs[]
| select((.stat.frontend_question_id|tostring) == $id)
| (if .difficulty.level==1 then "Easy"
   elif .difficulty.level==2 then "Medium"
   else "Hard" end)
')

# Validate problem data was found
if [[ -z "$PROBLEM_TITLE" ]] || [[ "$PROBLEM_TITLE" == "null" ]]; then
    echo "Error: Could not find problem #$PROBLEM_NUMBER in LeetCode API." >&2
    exit 1
fi

if [[ -z "$PROBLEM_SLUG" ]] || [[ "$PROBLEM_SLUG" == "null" ]]; then
    echo "Error: Could not find problem slug for #$PROBLEM_NUMBER." >&2
    exit 1
fi

PROBLEM_URL="https://leetcode.com/problems/$PROBLEM_SLUG/description/"

# Fetch daily problem ID (non-critical, continue if it fails)
DAILY_ID=$(curl -s https://alfa-leetcode-api.onrender.com/daily \
  | grep -oP '"questionFrontendId":"\K\d+' 2>/dev/null || echo "")

if [[ -z "$DAILY_ID" ]]; then
    echo "Warning: Could not determine daily problem" >&2
    DAILY_ID="N/A"
fi

POTD=""
if [[ "$PROBLEM_NUMBER" == "$DAILY_ID" ]]; then
    POTD=" 🌟 POTD"
    echo "✓ This is today's Problem of the Day!" >&2
fi


FILE=$(git show --pretty="" --name-only "$COMMIT_HASH" | head -n 1)

# Check if a file was found in the commit
if [[ -z "$FILE" ]]; then
    echo "Error: Could not find code file from commit $COMMIT_HASH." >&2
    exit 1
fi

EXT="${FILE##*.}"

# Extract code content from the commit
CODE_CONTENT=$(git show "$COMMIT_HASH:$FILE" 2>/dev/null | sed 's/^[0-9]*//g')

if [[ -z "$CODE_CONTENT" ]]; then
    echo "Error: Could not extract code content from file $FILE." >&2
    exit 1
fi

echo "Processing Problem #$PROBLEM_NUMBER: $PROBLEM_TITLE ($DIFFICULTY)"
echo "Time Beats: $TIME_BEATS, Memory Beats: $MEMORY_BEATS, Commit: $COMMIT_HASH, Solved At: $COMMIT_TIME"
echo "URL: $PROBLEM_URL"
echo "Code File: $FILE"
echo "$CODE_CONTENT"

# Build the new entry in a temp file
TMPFILE=$(mktemp)
{
echo ""
echo "<details>"
echo "<summary><h3>$PROBLEM_NUMBER. $PROBLEM_TITLE$POTD</h3></summary>"
echo ""
echo "\`$DIFFICULTY\` \`Time Beats: $TIME_BEATS\` \`Memory Beats: $MEMORY_BEATS\` \`Commit:$COMMIT_HASH\` \`Solved At: $COMMIT_TIME\` <code><a href=\"$PROBLEM_URL\" target=\"_blank\">LINK</a></code>"
echo ""
echo '```'"$EXT"
echo "$CODE_CONTENT"
echo '```'
echo ""
echo "</details>"
echo ""
} > "$TMPFILE"

# Prepend the entry right after the <!-- SUBMISSIONS --> marker
awk -v tmpfile="$TMPFILE" '
/<!-- SUBMISSIONS -->/ {
    print
    while ((getline line < tmpfile) > 0) print line
    close(tmpfile)
    next
}
{ print }
' README.md > README.tmp && mv README.tmp README.md

rm -f "$TMPFILE"

# Export variables for GitHub Actions commit message
if [[ -n "$GITHUB_ENV" ]]; then
    echo "LEETCODE_PROBLEM_NUMBER=$PROBLEM_NUMBER" >> "$GITHUB_ENV"
    echo "LEETCODE_PROBLEM_TITLE=$PROBLEM_TITLE" >> "$GITHUB_ENV"
    echo "LEETCODE_COMMIT_DATE=${COMMIT_TIME:0:10}" >> "$GITHUB_ENV"
fi