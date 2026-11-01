1class Solution {
2public:
3    int firstUniqChar(string s) {
4        unordered_map<char, int> freq;
5        for (char c : s) {
6            freq[c]++;
7        }
8        for (int i = 0; i < s.length(); i++) {
9            if (freq[s[i]] == 1) {
10                return i;
11            }
12        }
13        return -1;
14    }
15};