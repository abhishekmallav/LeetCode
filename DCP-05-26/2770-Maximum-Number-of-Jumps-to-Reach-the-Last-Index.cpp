1class Solution {
2public:
3    int n;
4
5    int solve(int i, vector<int>& nums, int target, vector<int>& t) {
6        if (i == n - 1) {
7            return t[i] = 0;
8        }
9
10        if (t[i] != INT_MIN) {
11            return t[i];
12        }
13
14        int result = INT_MIN;
15
16        for (int j = i + 1; j < n; j++) {
17            if (abs(nums[i] - nums[j]) <= target) {
18                int temp = 1 + solve(j, nums, target, t);
19
20                result = max(result, temp);
21            }
22        }
23        return t[i] = result;
24    }
25
26    int maximumJumps(vector<int>& nums, int target) {
27        n = nums.size();
28        vector<int> t(n + 1, INT_MIN);
29        int result = solve(0, nums, target, t);
30        return result < 0 ? -1 : result;
31    }
32};