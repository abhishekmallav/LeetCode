#!/usr/bin/env bash
set -e

RAW_COMMIT=$(git log -1 --pretty=format:"%h - %s")
COMMIT_TIME=$(TZ=Asia/Kolkata git log -1 --pretty=format:"%cd" --date=format:"%Y-%m-%d %H:%M:%S")
COMMIT_HASH=$(echo "$RAW_COMMIT" | awk '{print $1}')

PROBLEM_NUMBER=$(echo "$RAW_COMMIT" | grep -oE '\[[0-9]+\]' | tr -d '[]')

TIME_BEATS=$(echo "$RAW_COMMIT" \
  | grep -oE 'Time Beats: [0-9.]+%' \
  | grep -oE '[0-9.]+%')

MEMORY_BEATS=$(echo "$RAW_COMMIT" \
  | grep -oE 'Memory Beats: [0-9.]+%' \
  | grep -oE '[0-9.]+%')


PROBLEM_DATA=$(curl -s https://leetcode.com/api/problems/all/)

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

PROBLEM_URL="https://leetcode.com/problems/$PROBLEM_SLUG/description/"

DAILY_ID=$(curl -s https://alfa-leetcode-api.onrender.com/daily \
  | grep -oP '"questionFrontendId":"\K\d+' 2>/dev/null)

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
EXT="${FILE##*.}"

CODE_CONTENT=$(git show "$COMMIT_HASH:$FILE" 2>/dev/null | sed 's/^[0-9]*//g')

echo "Processing Problem #$PROBLEM_NUMBER: $PROBLEM_TITLE ($DIFFICULTY)"
echo "Time Beats: $TIME_BEATS, Memory Beats: $MEMORY_BEATS, Commit: $COMMIT_HASH, Solved At: $COMMIT_TIME"
echo "URL: $PROBLEM_URL"
echo "Code File: $FILE"
echo "$CODE_CONTENT"

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
} >> README.md