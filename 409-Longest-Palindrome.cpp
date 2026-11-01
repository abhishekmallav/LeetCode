1class Solution {
2public:
3    int longestPalindrome(string s) {
4        int n = s.length();
5        vector<int> hash(128, 0);
6        for (auto i : s) {
7            hash[i]++;
8        }
9        int cnt1 = 0;
10        int cntEven = 0;
11        int cntOdd = 0;
12        for (int i = 0; i < 128; i++) {
13            if (hash[i] == 1) {
14                cnt1++;
15            } else if (hash[i] % 2 == 0 && hash[i] != 0) {
16                cntEven += hash[i];
17            } else if (hash[i] % 2 != 0 && hash[i] != 1) {
18                cntEven += hash[i] - 1;
19                cntOdd++;
20            }
21        }
22        if (cntOdd > 0 || cnt1 > 0) {
23            return cntEven + 1;
24        }
25        return cntEven;
26    }
27};