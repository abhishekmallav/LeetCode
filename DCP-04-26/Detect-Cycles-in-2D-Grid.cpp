1class Solution {
2public:
3    int m, n;
4    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
5
6    bool cycleDetectDFS(int r, int c, int prev_r, int prev_c,
7                        vector<vector<char>>& grid,
8                        vector<vector<bool>>& visited) {
9
10        if (visited[r][c]) {
11            return true;
12        }
13
14        visited[r][c] = true;
15
16        // explore neighbours
17        for (auto& dir : directions) {
18            int new_r = r + dir[0];
19            int new_c = c + dir[1];
20
21            if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n &&
22                grid[new_r][new_c] == grid[r][c]) {
23                if (new_r == prev_r && new_c == prev_c)
24                    continue;
25
26                if (cycleDetectDFS(new_r, new_c, r, c, grid, visited)) {
27                    return true;
28                }
29            }
30        }
31
32        return false;
33    }
34    bool containsCycle(vector<vector<char>>& grid) {
35        m = grid.size();
36        n = grid[0].size();
37
38        vector<vector<bool>> visited(m, vector<bool>(n, false));
39
40        for (int i = 0; i < m; i++) {
41            for (int j = 0; j < n; j++) {
42                if (!visited[i][j] &&
43                    cycleDetectDFS(i, j, i, j, grid, visited)) {
44                    return true;
45                }
46            }
47        }
48
49        return false;
50    }
51};