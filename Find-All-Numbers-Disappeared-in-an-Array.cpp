1class Solution {
2public:
3    vector<int> findDisappearedNumbers(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        vector<int> ans;
6        int n = nums.size();
7        int j = 0;
8        int i = 1;
9
10        while (i <= n) {
11            if (j < n && i == nums[j]) {
12                i++;
13                j++;
14            }
15
16            else if (j < n && nums[j] < i) {
17                j++;
18            }
19
20            else {
21                ans.push_back(i);
22                i++;
23            }
24        }
25        return ans;
26    }
27};