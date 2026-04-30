1class Solution {
2public:
3    int maxPathScore(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        vector<vector<vector<int>>> t(
8            m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
9
10        for (int i = m - 1; i >= 0; i--) {
11            for (int j = n - 1; j >= 0; j--) {
12                for (int cost = k; cost >= 0; cost--) {
13
14                    int newCost = cost + (grid[i][j] > 0);
15
16                    if (newCost > k)
17                        continue;
18
19                    if (i == m - 1 && j == n - 1) {
20                        t[i][j][cost] = grid[i][j];
21                        continue;
22                    }
23
24                    int down = -1;
25                    int right = -1;
26
27                    if (i + 1 < m)
28                        down = t[i + 1][j][newCost];
29
30                    if (j + 1 < n)
31                        right = t[i][j + 1][newCost];
32
33                    int bestNext = max(down, right);
34
35                    if (bestNext != -1) {
36                        t[i][j][cost] = grid[i][j] + bestNext;
37                    }
38                }
39            }
40        }
41
42        return t[0][0][0];
43    }
44};