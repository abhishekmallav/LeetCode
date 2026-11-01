1class Solution {
2public:
3    int getMinDistance(vector<int>& nums, int target, int start) {
4        int n = nums.size();
5        int ans = INT_MAX;
6        for (int i = 0; i < n; i++) {
7            if (nums[i] == target) {
8                ans = min(ans, abs(i - start));
9            }
10        }
11        return ans;
12    }
13};