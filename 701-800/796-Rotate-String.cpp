1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        int n = s.length();
5
6        for (int i = 0; i < n; i++) {
7            char ch = s[0];
8            s.erase(0, 1);
9            s += ch;
10            if (s == goal) {
11                return true;
12            }
13        }
14        return false;
15    }
16};