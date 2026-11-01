1class Solution {
2public:
3    int numPairsDivisibleBy60(vector<int>& time) {
4        int n = time.size();
5        long long count = 0;
6        vector<int> remainder(60, 0);
7
8        for (int i = 0; i < n; i++) {
9            int rem = time[i] % 60;
10            remainder[rem]++;
11        }
12
13        for (int i = 1; i < 30; i++) {
14            count += (long long)remainder[i] * remainder[60 - i];
15        }
16
17        if (remainder[0] > 1) {
18            count += (long long)remainder[0] * (remainder[0] - 1) / 2;
19        }
20
21        if (remainder[30] > 1) {
22            count += (long long)remainder[30] * (remainder[30] - 1) / 2;
23        }
24
25        return (int)count;
26    }
27};