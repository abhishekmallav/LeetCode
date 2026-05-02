1class Solution {
2public:
3    bool isGood(int num) {
4        bool changed = false;
5
6        while (num > 0) {
7            int digit = num % 10;
8
9            if (digit == 3 || digit == 4 || digit == 7)
10                return false;
11            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
12                changed = true;
13
14            num /= 10;
15        }
16        return changed;
17    }
18
19    int rotatedDigits(int n) {
20        int count = 0;
21
22        for (int i = 1; i <= n; i++) {
23            if (isGood(i)) {
24                count++;
25            }
26        }
27        return count;
28    }
29};
30