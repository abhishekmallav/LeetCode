1class Solution {
2public:
3    int countPrimeSetBits(int left, int right) {
4        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
5
6        int result = 0;
7        for (int i = left; i <= right; i++) {
8            int setBits = __builtin_popcount(i);
9            if (primes.count(setBits)) {
10                result++;
11            }
12        }
13        return result;
14    }
15};