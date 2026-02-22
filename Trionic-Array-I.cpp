1class Solution {
2public:
3    bool isTrionic(vector<int>& nums) {
4        int n = nums.size();
5        if (n < 3) {
6            return false;
7        }
8
9        int i = 0;
10
11        // increasing
12        while (i + 1 < n && nums[i] < nums[i + 1]) {
13            i++;
14        }
15        if (i == 0 || i == n - 1) {
16            return false;
17        }
18
19        // decreasing
20        int j = i;
21        while (j + 1 < n && nums[j] > nums[j + 1]) {
22            j++;
23        }
24        if (j == i || j == n - 1) {
25            return false;
26        }
27
28        // increasing
29        while (j + 1 < n && nums[j] < nums[j + 1]) {
30            j++;
31        }
32
33        return j == n - 1;
34    }
35};
36