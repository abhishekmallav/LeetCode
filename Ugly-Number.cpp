1class Solution {
2public:
3    bool isUgly(int n) {
4        if (n == 1) {
5            return true;
6        }
7        if (n <= 0) {
8            return false;
9        }
10        while (n > 1) {
11            if (n % 2 == 0) {
12                n /= 2;
13                continue;
14            }
15            if (n % 3 == 0) {
16                n /= 3;
17                continue;
18            }
19            if (n % 5 == 0) {
20                n /= 5;
21                continue;
22            }
23            return false;
24        }
25        return true;
26    }
27};