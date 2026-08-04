class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        int n = nums.size();
        int start = nums[0];
        int end = nums[n - 1];
        int idx = 0;

        for (int i = start; i <= end; i++) {
            if (i != nums[idx]) {
                ans.push_back(i);
            } else {
                idx++;
            }
        }

        return ans;
    }
};