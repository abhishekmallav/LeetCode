1class Solution {
2public:
3    int getReverse(int n) {
4        int result = 0;
5
6        while (n) {
7            int rem = n % 10;
8            result = (result * 10) + rem;
9            n /= 10;
10        }
11
12        return result;
13    }
14
15    int mirrorDistance(int n) { return abs(n - getReverse(n)); }
16};
17