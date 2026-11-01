1class Solution {
2public:
3    bool canConstruct(string ransomNote, string magazine) {
4        vector<int> hashRansom(26, 0);
5        vector<int> hashMag(26, 0);
6
7        for (auto i : ransomNote) {
8            hashRansom[i - 'a']++;
9        }
10
11        for (auto i : magazine) {
12            hashMag[i - 'a']++;
13        }
14
15        for (auto i : ransomNote) {
16            if (hashRansom[i - 'a'] > hashMag[i - 'a']) {
17                return false;
18            }
19        }
20
21        return true;
22    }
23};