1class Solution {
2public:
3    int concatenatedBinary(int n) {
4        int M = 1e9 + 7;
5        long long ans = 0;
6        for (int i = 1; i <= n; i++) {
7            int bits = log2(i) + 1;
8            ans = ((ans << bits) % M + i) % M;
9        }
10        return ans;
11    }
12};