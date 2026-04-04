1class Solution {
2public:
3    int countSegments(string s) {
4        int cnt = 0;
5        for (int i = 0; i < s.length(); i++) {
6            if (s[i] != ' ') {
7                if (i == 0 || s[i - 1] == ' ') {
8                cnt++;
9                }
10            }
11        }
12        return cnt;
13    }
14};