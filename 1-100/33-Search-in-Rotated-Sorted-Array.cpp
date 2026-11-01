class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int L = 0;
        int R = n - 1;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[L]) {
                if (nums[L] <= target && nums[mid] >= target) {
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            } else {
                if (nums[mid] <= target && nums[R] >= target) {
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
        }
        return -1;
    }
};