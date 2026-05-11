1class Solution {
2public:
3    vector<int> separateDigits(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans;
6
7        for (int i = 0; i < n; i++) {
8            vector<int> tmp;
9            while (nums[i] > 0) {
10                tmp.push_back(nums[i] % 10);
11                nums[i] /= 10;
12            }
13            for (int j = tmp.size() - 1; j >= 0; j--) {
14                ans.push_back(tmp[j]);
15            }
16        }
17        return ans;
18    }
19};