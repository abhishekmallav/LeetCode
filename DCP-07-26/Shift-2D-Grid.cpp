class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int size = m * n;

        vector<int> temp(size);
        int ind = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                temp[ind++] = grid[i][j];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n));
        ind = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = ((ind - k) % size + size) % size;
                ans[i][j] = temp[idx];
                ind++;
            }
        }
        return ans;
    }
};