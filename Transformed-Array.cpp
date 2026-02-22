1class Solution {
2public:
3    vector<int> constructTransformedArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> result;
6
7        for (int i = 0; i < n; i++) {
8            int j = i + nums[i];
9
10            while (j < 0) {
11                j += n;
12            }
13            while (j >= n) {
14                j -= n;
15            }
16
17            result.push_back(nums[j]);
18        }
19
20        return result;
21    }
22};
23