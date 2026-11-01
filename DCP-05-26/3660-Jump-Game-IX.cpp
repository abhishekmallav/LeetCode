1class Solution {
2public:
3    vector<int> maxValue(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> maxLeft(n);  // maxLeft[i] = max element from index 0 to i
7        vector<int> minRight(n); // minRight[i] = min element from i+1 to n
8
9        maxLeft[0] = nums[0];
10        minRight[n - 1] = nums[n - 1];
11
12        for (int i = 1; i < n; i++) {
13            maxLeft[i] = max(nums[i], maxLeft[i - 1]);
14        }
15
16        for (int i = n - 2; i >= 0; i--) {
17            minRight[i] = min(nums[i], minRight[i + 1]);
18        }
19
20        vector<int> ans(n);
21
22        ans[n - 1] = maxLeft[n - 1];
23
24        for (int i = n - 2; i >= 0; i--) {
25            if (maxLeft[i] <= minRight[i + 1]) { 
26                ans[i] = maxLeft[i];
27            } else {
28                ans[i] = ans[i + 1];
29            }
30        }
31
32        return ans;
33    }
34};
35