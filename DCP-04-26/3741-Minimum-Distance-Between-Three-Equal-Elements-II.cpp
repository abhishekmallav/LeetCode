1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        int n = nums.size();
5        int ans = INT_MAX;
6        unordered_map<int, vector<int>> mp;
7
8        for (int k = 0; k < n; k++) {
9            mp[nums[k]].push_back(k);
10            
11            if (mp[nums[k]].size() >= 3) {
12                vector<int>& vec = mp[nums[k]];
13                int siz = vec.size();
14                int i = vec[siz - 3];
15                ans = min(ans, 2 * (k - i));
16            }
17        }
18        if (ans != INT_MAX) {
19            return ans;
20        }
21        return -1;
22    }
23};