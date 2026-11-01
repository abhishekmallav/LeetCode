1class Solution {
2public:
3    bool isGood(vector<int>& nums) {
4        int n = nums.size();
5
6        if (n == 1) {
7            return false;
8        }
9
10        sort(nums.begin(), nums.end());
11
12        for (int i = 0; i <= n - 2; i++) {
13            if (nums[i] == i + 1) {
14                continue;
15            }
16            return false;
17        }
18        if (nums[n - 1] == nums[n - 2]) {
19            return true;
20        }
21        return false;
22    }
23};