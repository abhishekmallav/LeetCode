1class Solution {
2public:
3
4    bool checkBalanced(vector<int>& freq) {
5        int common = 0;
6        for(int i = 0; i < 26; i++) {
7            if(freq[i] == 0) continue;
8            if(common == 0)
9                common = freq[i];
10            else if(freq[i] != common) {
11                return false;
12            }
13        }
14
15        return true;
16    }
17
18    int longestBalanced(string s) {
19        int n = s.length();
20
21        int maxLen = 0;
22
23        for(int i = 0; i < n; i++) {
24            vector<int> freq(26, 0);
25
26            for(int j = i; j < n; j++) {
27                freq[s[j] - 'a']++;
28
29                //i..j
30                if(checkBalanced(freq)) {
31                    maxLen = max(maxLen, j-i+1);
32                }
33            }
34        }
35
36        return maxLen;
37    }
38};