class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), m = nums[n / 2], sol = 0;

        for (int num : nums) {
            sol += abs(num - m);
        }
        
        return sol;
    }
};