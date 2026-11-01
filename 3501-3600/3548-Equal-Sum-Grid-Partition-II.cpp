1class Solution {
2public:
3    typedef long long ll;
4    ll total = 0;
5
6    bool checkHorCuts(vector<vector<int>>& grid) {
7        int m = grid.size();
8        int n = grid[0].size();
9
10        unordered_set<ll> st;
11        ll top = 0;
12
13        for (int i = 0; i <= m - 2; i++) {
14
15            for (int j = 0; j < n; j++) {
16                st.insert(grid[i][j]);
17                top += grid[i][j];
18            }
19
20            ll bottom = (total - top);
21            ll diff = top - bottom;
22
23            if (diff == 0)
24                return true;
25
26            if (diff == (ll)grid[0][0])
27                return true;
28            if (diff == (ll)grid[0][n - 1])
29                return true;
30            if (diff == (ll)grid[i][0])
31                return true;
32
33            if (i > 0 && n > 1 && st.count(diff)) {
34                return true;
35            }
36        }
37
38        return false;
39    }
40
41    bool canPartitionGrid(vector<vector<int>>& grid) {
42        int m = grid.size();
43        int n = grid[0].size();
44
45        for (int i = 0; i < m; i++) {
46            for (int j = 0; j < n; j++) {
47                total += grid[i][j];
48            }
49        }
50
51        if (checkHorCuts(grid)) {
52            return true;
53        }
54
55        reverse(begin(grid), end(grid));
56
57        if (checkHorCuts(grid)) {
58            return true;
59        }
60
61        reverse(begin(grid), end(grid));
62        vector<vector<int>> transposeGrid(n, vector<int>(m)); // n*m
63
64        for (int i = 0; i < m; i++) {
65            for (int j = 0; j < n; j++) {
66                transposeGrid[j][i] = grid[i][j];
67            }
68        }
69
70        if (checkHorCuts(transposeGrid)) {
71            return true;
72        }
73
74        reverse(begin(transposeGrid), end(transposeGrid));
75
76        if (checkHorCuts(transposeGrid)) {
77            return true;
78        }
79
80        return false;
81    }
82};