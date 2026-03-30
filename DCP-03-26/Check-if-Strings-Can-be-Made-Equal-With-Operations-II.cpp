1class Solution {
2public:
3    bool checkStrings(string s1, string s2) {
4        vector<int> even1(26, 0);
5        vector<int> odd1(26, 0);
6        vector<int> even2(26, 0);
7        vector<int> odd2(26, 0);
8
9        for (int i = 0; i < s1.size(); i++) {
10            if (i % 2 == 0) {
11                even1[s1[i] - 'a']++;
12                even2[s2[i] - 'a']++;
13            } else {
14                odd1[s1[i] - 'a']++;
15                odd2[s2[i] - 'a']++;
16            }
17        }
18
19        if (even1 == even2 && odd1 == odd2) {
20            return true;
21        }
22        return false;
23    }
24};