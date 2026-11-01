1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int L = 0;
5        int R = nums.size() - 1;
6        
7        while (L < R) {
8            int mid = L + (R - L) / 2;
9
10            if (nums[mid] > nums[R]) {
11                L = mid + 1;
12            } else {
13                R = mid;
14            }
15        }
16        return nums[L];
17    }
18};