1class Solution {
2public:
3    bool canPartitionGrid(vector<vector<int>>& grid) {
4        int row = grid.size();
5        int col = grid[0].size();
6
7        long long prev = 0;
8        vector<vector<long long>> HSum(row, vector<long long>(col, 0));
9        vector<vector<long long>> VSum(row, vector<long long>(col, 0));
10
11        // row wise cumulative sum
12        if (row > 1) {
13            for (int i = 0; i < row; i++) {
14                for (int j = 0; j < col; j++) {
15                    prev += grid[i][j];
16                    HSum[i][j] = prev;
17                }
18            }
19        }
20
21        // column wise cumulative sum
22        prev = 0;
23        if (col > 1) {
24            for (int i = 0; i < col; i++) {
25                for (int j = 0; j < row; j++) {
26                    prev += grid[j][i];
27                    VSum[j][i] = prev;
28                }
29            }
30        }
31
32        long long total;
33        if (row > 1) {
34            total = HSum[row - 1][col - 1];
35        } else {
36            total = VSum[row - 1][col - 1];
37        }
38
39        // Horizontal cuts
40        for (int i = 0; i < row - 1; i++) {
41            if (HSum[i][col - 1] == total - HSum[i][col - 1]) {
42                return true;
43            }
44        }
45
46        // Vertical cuts
47        for (int j = 0; j < col - 1; j++) {
48            if (VSum[row - 1][j] == total - VSum[row - 1][j]) {
49                return true;
50            }
51        }
52
53        return false;
54    }
55};