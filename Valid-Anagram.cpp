1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        int hashS[26] = {0};
5        int hashT[26] = {0};
6
7        for (int i = 0; i < s.size(); i++) {
8            hashS[s[i] - 'a']++;
9        }
10        
11        for (int i = 0; i < t.size(); i++) {
12            hashT[t[i] - 'a']++;
13        }
14
15        for (int i = 0; i < 26; i++) {
16            if (hashS[i] != hashT[i]) {
17                return false;
18            }
19        }
20        return true;
21    }
22};