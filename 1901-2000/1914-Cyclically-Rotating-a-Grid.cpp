1class Solution {
2public:
3    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        int layers = min(m, n) / 2;
8
9        for (int layer = 0; layer < layers; layer++) {
10
11            vector<int> nums;
12
13            int top = layer;
14            int bottom = m - layer - 1;
15            int left = layer;
16            int right = n - layer - 1;
17
18            for (int j = left; j <= right; j++) {
19                nums.push_back(grid[top][j]);
20            }
21
22            for (int i = top + 1; i <= bottom - 1; i++) {
23                nums.push_back(grid[i][right]);
24            }
25
26            for (int j = right; j >= left; j--) {
27                nums.push_back(grid[bottom][j]);
28            }
29
30            for (int i = bottom - 1; i >= top + 1; i--) {
31                nums.push_back(grid[i][left]);
32            }
33
34            int len = nums.size();
35
36            int nomralized_k = k % len;
37
38            rotate(begin(nums), begin(nums) + nomralized_k, end(nums));
39
40            int idx = 0;
41
42            for (int j = left; j <= right; j++) {
43                grid[top][j] = nums[idx++];
44            }
45
46            for (int i = top + 1; i <= bottom - 1; i++) {
47                grid[i][right] = nums[idx++];
48            }
49
50            for (int j = right; j >= left; j--) {
51                grid[bottom][j] = nums[idx++];
52            }
53
54            for (int i = bottom - 1; i >= top + 1; i--) {
55                grid[i][left] = nums[idx++];
56            }
57        }
58
59        return grid;
60    }
61};