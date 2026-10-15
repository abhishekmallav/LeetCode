class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> unique;
            for (int j = i; j < n; j++) {
                unique.insert(nums[j]);
                int uni = unique.size();
                ans += (uni * uni);
            }
        }
        return ans;
    }
};