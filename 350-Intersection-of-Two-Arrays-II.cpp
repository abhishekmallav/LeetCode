1class Solution {
2public:
3    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
4
5        sort(nums1.begin(), nums1.end());
6        sort(nums2.begin(), nums2.end());
7
8        vector<int> ans;
9        int i = 0;
10        int j = 0;
11
12        while (i < nums1.size() && j < nums2.size()) {
13            if (nums1[i] == nums2[j]) {
14                ans.push_back(nums1[i]);
15                i++;
16                j++;
17            } else if (nums1[i] < nums2[j]) {
18                i++;
19            } else {
20
21                j++;
22            }
23        }
24
25        return ans;
26    }
27};