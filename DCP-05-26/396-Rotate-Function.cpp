1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int n = nums.size();
5
6        int sum = 0;
7        int F = 0;
8
9        for (int i = 0; i < n; i++) {
10            sum += nums[i];
11            F += i * nums[i];
12        }
13
14        int result = F;
15
16        for (int k = 0; k <= n - 1; k++) {
17            int newF = F + sum - n * nums[n - 1 - k];
18
19            result = max(result, newF);
20
21            F = newF;
22        }
23
24        return result;
25    }
26};