class Solution {
public:
    int minMoves(vector<int>& nums) {
        auto maxi = ranges::max_element(nums);
        int sol = 0;

        for (int num : nums) {
            sol += *maxi - num;
        }
        
        return sol;
    }
};