1class Solution {
2public:
3    bool isHappy(int n) {
4        unordered_set<long long> seen;
5        long long num = n;
6
7        while (num != 1) {
8            if (seen.find(num) != seen.end()) {
9                return false;
10            }
11            seen.insert(num);
12            long long sum = 0;
13            while (num > 0) {
14                int digit = num % 10;
15                sum += (digit * digit);
16                num /= 10;
17            }
18            num = sum;
19        }
20        
21        return true;
22    }
23};