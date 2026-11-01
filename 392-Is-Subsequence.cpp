1class Solution {
2public:
3    bool isSubsequence(string s, string t) {
4        int i = 0;
5        int j = 0;
6        
7        while (i < s.length() && j < t.length()) {
8            if (s[i] == t[j]) {
9                i++;
10            }
11            j++;
12        }
13        
14        return i == s.length();
15    }
16};