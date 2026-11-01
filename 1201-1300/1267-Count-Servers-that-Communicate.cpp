class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<int> rowCnt(row, 0);
        vector<int> colCnt(col, 0);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }

        int res = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    if (rowCnt[i] > 1 || colCnt[j] > 1) {
                        res++;
                    }
                }
            }
        }

        return res;
    }
};