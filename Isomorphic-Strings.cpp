1class Solution {
2public:
3    bool isIsomorphic(string s, string t) {
4        vector<int> mapS(256, -1);
5        vector<int> mapT(256, -1);
6
7        for (int i = 0; i < s.size(); i++) {
8            char charS = s[i];
9            char charT = t[i];
10
11            // If s[i] has been seen before, check if it maps to the same t[i]
12            if (mapS[charS] != -1 && mapS[charS] != charT) {
13                return false;
14            }
15
16            // If t[i] has been seen before, check if it maps to the same s[i]
17            if (mapT[charT] != -1 && mapT[charT] != charS) {
18                return false;
19            }
20
21            mapS[charS] = charT;
22            mapT[charT] = charS;
23        }
24
25        return true;
26    }
27};