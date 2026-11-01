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
12            } else if (nums[mid] < nums[R]) {
13                R = mid;
14            } else {
15                R--;
16            }
17        }
18        return nums[L];
19    }
20};