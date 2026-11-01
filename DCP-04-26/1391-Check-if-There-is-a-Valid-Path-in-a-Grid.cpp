1class Solution {
2public:
3    int m, n;
4
5    unordered_map<int, vector<vector<int>>> directions = {
6        {1, {{0, -1}, {0, 1}}},  {2, {{-1, 0}, {1, 0}}},
7        {3, {{0, -1}, {1, 0}}},  {4, {{0, 1}, {1, 0}}},
8        {5, {{0, -1}, {-1, 0}}}, {6, {{-1, 0}, {0, 1}}}};
9
10    bool dfs(vector<vector<int>>& grid, int i, int j,
11             vector<vector<bool>>& visited) {
12        if (i == m - 1 && j == n - 1)
13            return true;
14
15        visited[i][j] = true;
16
17        for (auto& dir : directions[grid[i][j]]) {
18            int new_i = i + dir[0];
19            int new_j = j + dir[1];
20
21            if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n ||
22                visited[new_i][new_j])
23                continue;
24
25            // IMPORTANT = can you come back to i and j from new_i and new_j
26            for (auto& backDir : directions[grid[new_i][new_j]]) {
27                if (new_i + backDir[0] == i && new_j + backDir[1] == j) {
28                    if (dfs(grid, new_i, new_j, visited)) {
29                        return true;
30                    }
31                }
32            }
33        }
34
35        return false;
36    }
37
38    bool hasValidPath(vector<vector<int>>& grid) {
39        m = grid.size();
40        n = grid[0].size();
41
42        vector<vector<bool>> visited(m, vector<bool>(n, false));
43        // T.C : O(m*n)
44
45        return dfs(grid, 0, 0, visited);
46    }
47};
48