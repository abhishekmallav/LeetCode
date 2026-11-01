1class Solution {
2public:
3    bool isPowerOfTwo(int n) {
4        if (n <= 0)
5            return false;
6
7        int count = 0;
8        while (n > 0) {
9            if ((n & 1) == 1) {
10                count++;
11            }
12            n = n >> 1;
13        }
14
15        if (count == 1) {
16            return true;
17        }
18        return false;
19    }
20};