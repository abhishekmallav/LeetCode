1class Solution {
2public:
3    int numberOfSubmatrices(vector<vector<char>>& grid) {
4        int row = grid.size();
5        int col = grid[0].size();
6        
7        vector<vector<int>> sum(row, vector<int>(col, 0));
8        vector<vector<int>> countX(row, vector<int>(col, 0));
9
10        for (int i = 0; i < row; i++) {
11            for (int j = 0; j < col; j++) {
12
13                int val = 0;
14                if (grid[i][j] == 'X') {
15                    val = 1;
16                } else if (grid[i][j] == 'Y') {
17                    val = -1;
18                }
19
20                int xval = (grid[i][j] == 'X') ? 1 : 0;
21
22                sum[i][j] = val;
23                countX[i][j] = xval;
24
25                if (i > 0) {
26                    sum[i][j] += sum[i - 1][j];
27                    countX[i][j] += countX[i - 1][j];
28                }
29                if (j > 0) {
30                    sum[i][j] += sum[i][j - 1];
31                    countX[i][j] += countX[i][j - 1];
32                }
33                if (i > 0 && j > 0) {
34                    sum[i][j] -= sum[i - 1][j - 1];
35                    countX[i][j] -= countX[i - 1][j - 1];
36                }
37            }
38        }
39
40        int ans = 0;
41
42        for (int i = 0; i < row; i++) {
43            for (int j = 0; j < col; j++) {
44                if (sum[i][j] == 0 && countX[i][j] > 0) {
45                    ans++;
46                }
47            }
48        }
49
50        return ans;
51    }
52};