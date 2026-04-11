1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        int n = nums1.size();
5        vector<int> vec(n, -1);
6
7        for (int i = 0; i < n; i++) {
8            int j = 0;
9
10            while (j < nums2.size() && nums2[j] != nums1[i]) {
11                j++;
12            }
13
14            for (int k = j + 1; k < nums2.size(); k++) {
15                if (nums2[k] > nums1[i]) {
16                    vec[i] = nums2[k];
17                    break;
18                }
19            }
20        }
21        return vec;
22    }
23};