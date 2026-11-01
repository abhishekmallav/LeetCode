class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        auto mini = ranges::min_element(nums);
        int sol = 0;

        for (int i = 0; i < n; i++) {
            sol += nums[i] - *mini;
        }
        return sol;
    }
};