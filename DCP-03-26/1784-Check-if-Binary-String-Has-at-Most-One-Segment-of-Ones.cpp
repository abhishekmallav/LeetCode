1class Solution {
2public:
3    bool checkOnesSegment(string s) {
4        int n = s.length();
5
6        // we have to check if the 01 appears or not
7        // 10000 true no (01)
8        // 111000 true no (01)
9        // 10001 false (01) exists
10        // 110011 false (01) exists
11
12        for (int i = 0; i < n; i++) {
13            if (s[i] == '0' && s[i + 1] == '1') {
14                return false;
15            }
16        }
17        return true;
18    }
19};