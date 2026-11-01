class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        bool op = false;
        int an = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                an = an & nums[i];
                op = true;
            }
        }
        return (!op) ? 0 : an;
    }
};