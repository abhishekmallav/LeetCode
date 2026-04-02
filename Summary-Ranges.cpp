1class Solution {
2public:
3    vector<string> summaryRanges(vector<int>& nums) {
4        vector<string> ans;
5        int n = nums.size();
6        if (n == 0) return ans;
7
8        for (int i = 0; i < n; i++) {
9            int start = nums[i];
10            
11            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
12                i++;
13            }
14            
15            if (start == nums[i]) {
16                ans.push_back(to_string(start));
17            } else {
18                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
19            }
20        }
21        
22        return ans;
23    }
24};