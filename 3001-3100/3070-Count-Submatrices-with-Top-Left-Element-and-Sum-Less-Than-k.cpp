1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& grid, int k) {
4        int row = grid.size();
5        int col = grid[0].size();
6        int ans = 0;
7        for (int i = 0; i < row; i++) {
8            for (int j = 0; j < col; j++) {
9                if (i > 0) {
10                    grid[i][j] += grid[i - 1][j];
11                }
12                if (j > 0) {
13                    grid[i][j] += grid[i][j - 1];
14                }
15                if (i > 0 && j > 0) {
16                    grid[i][j] -= grid[i - 1][j - 1];
17                }
18            }
19        }
20        for (int i = 0; i < row; i++) {
21            for (int j = 0; j < col; j++) {
22                if (grid[i][j] <= k) {
23                    ans++;
24                }
25            }
26        }
27        return ans;
28    }
29};