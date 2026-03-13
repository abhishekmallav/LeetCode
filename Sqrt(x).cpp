1class Solution {
2public:
3    int mySqrt(int x) {
4        int L = 1;
5        int R = x;
6        int ans = 0;
7
8        while (L <= R) {
9            int mid = L + (R - L) / 2;
10            long long midSq = (long long)mid * mid;
11
12            if (midSq == x) {
13                return mid;
14            } else if (midSq < x) {
15                ans = mid;
16                L = mid + 1;
17            } else {
18                R = mid - 1;
19            }
20        }
21        return ans;
22    }
23};