1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> result(n, -1);
6
7        for (int i = 0; i < n; i++) {
8            int j = i + 1;
9            while (j < 2*n) {
10                if (nums[j % n] >= nums[i] + 1) {
11                    result[i] = nums[j % n];
12                    break;
13                }
14                j++;
15            }
16        }
17        return result;
18    }
19};