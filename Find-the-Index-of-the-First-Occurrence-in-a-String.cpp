1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        int n = haystack.length();
5        int m = needle.length();
6
7        if (m == 0)
8            return 0;
9
10        for (int i = 0; i <= n - m; i++) {
11            int j = 0;
12
13            for (j = 0; j < m; j++) {
14                if (haystack[i + j] != needle[j]) {
15                    break;
16                }
17            }
18
19            if (j == m) {
20                return i;
21            }
22        }
23
24        return -1;
25    }
26};