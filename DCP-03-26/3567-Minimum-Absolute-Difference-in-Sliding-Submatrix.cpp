1class Solution {
2public:
3    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
4        int row = grid.size();
5        int col = grid[0].size();
6
7        vector<vector<int>> ans(row - k + 1, vector<int>(col - k + 1, 0));
8        if (k == 1) {
9            return ans;
10        }
11        for (int i = 0; i <= row - k; i++) {
12            for (int j = 0; j <= col - k; j++) {
13
14                vector<int> tmp;
15
16                // collect k x k subgrid
17                for (int m = i; m < i + k; m++) {
18                    for (int n = j; n < j + k; n++) {
19                        tmp.push_back(grid[m][n]);
20                    }
21                }
22
23                sort(tmp.begin(), tmp.end());
24                auto it = unique(tmp.begin(), tmp.end());
25                tmp.erase(it, tmp.end());
26                
27                if (tmp.size() < 2) {
28                    ans[i][j] = 0;
29                    continue;
30                }
31
32                int minDiff = INT_MAX;
33
34                for (int o = 0; o < tmp.size() - 1; o++) {
35                    int diff = abs(tmp[o] - tmp[o + 1]);
36                    minDiff = min(minDiff, diff);
37
38                    if (minDiff == 0) {
39                        break;
40                    }
41                }
42
43                ans[i][j] = minDiff;
44            }
45        }
46
47        return ans;
48    }
49};