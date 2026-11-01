class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0, R = nums.size() - 1,mid;
        
        if (nums[L] <= nums[R]) return nums[L];

        while (L < R) {
            mid = L + (R - L) / 2;

            if (nums[mid] > nums[R]) {
                L = mid + 1;
            } 
            else {
                R = mid;
            }
        }
        return nums[mid];
    }
};