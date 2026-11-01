1class Solution {
2public:
3    int getCommon(vector<int>& nums1, vector<int>& nums2) {
4        for (int i = 0; i < nums1.size(); i++) {
5            int target = nums1[i];
6
7            int L = 0;
8            int R = nums2.size() - 1;
9
10            while (L <= R) {
11                int mid = L + (R - L) / 2;
12
13                if (nums2[mid] == target) {
14                    return target;
15                } else if (nums2[mid] < target) {
16                    L = mid + 1;
17                } else {
18                    R = mid - 1;
19                }
20            }
21        }
22
23        return -1;
24    }
25};