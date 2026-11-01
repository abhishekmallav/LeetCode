class Solution {
public:
    int m, n;

    bool dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';

        if (i + 1 < n && grid[i + 1][j] != '0') {
            dfs(i + 1, j, grid);
        }
        if (i - 1 >= 0 && grid[i - 1][j] != '0') {
            dfs(i - 1, j, grid);
        }
        if (j + 1 < m && grid[i][j + 1] != '0') {
            dfs(i, j + 1, grid);
        }
        if (j - 1 >= 0 && grid[i][j - 1] != '0') {
            dfs(i, j - 1, grid);
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '0') {
                    if (dfs(i, j, grid)) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};