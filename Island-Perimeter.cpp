1class Solution {
2public:
3    int islandPerimeter(vector<vector<int>>& grid) {
4        int row = grid.size();
5        int col = grid[0].size();
6
7        int peri = 0;
8
9        for (int i = 0; i < row; i++) {
10            for (int j = 0; j < col; j++) {
11                if (grid[i][j] == 1) {
12                    peri += 4;
13                    if (j + 1 < col && grid[i][j + 1] == 1) {
14                        peri--;
15                    }
16                    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
17                        peri--;
18                    }
19                    if (i + 1 < row && grid[i + 1][j] == 1) {
20                        peri--;
21                    }
22                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
23                        peri--;
24                    }
25                }
26            }
27        }
28        return peri;
29    }
30};