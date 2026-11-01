1class Solution {
2public:
3    char findTheDifference(string s, string t) {
4        vector<int> hashS(26, 0);
5        vector<int> hashT(26, 0);
6
7        for (auto i : s) {
8            hashS[i - 'a']++;
9        }
10        for (auto i : t) {
11            hashT[i - 'a']++;
12        }
13
14        for (int i = 0; i < 26; i++) {
15            if (hashS[i] + 1 == hashT[i]) {
16                return 'a' + i;
17            }
18        }
19        return 0;
20    }
21};