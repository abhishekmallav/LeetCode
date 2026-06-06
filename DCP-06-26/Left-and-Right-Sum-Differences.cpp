class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += nums[i - 1];
            leftSum[i] = sum;
        }
        sum = 0;
        for (int i = n - 2; i >= 0; i--) {
            sum += nums[i + 1];
            rightSum[i] = sum;
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }
        return ans;
    }
};