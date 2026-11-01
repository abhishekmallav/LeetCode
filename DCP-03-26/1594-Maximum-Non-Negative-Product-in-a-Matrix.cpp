1class Solution {
2public:
3    int m, n;
4    typedef long long ll;
5    int MOD = 1e9 + 7;
6
7    vector<vector<pair<ll, ll>>> t;
8
9    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
10        if (i == m - 1 && j == n - 1) {
11            return {grid[i][j], grid[i][j]};
12        }
13
14        ll maxVal = LLONG_MIN;
15        ll minVal = LLONG_MAX;
16
17        if (t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
18            return t[i][j];
19        }
20
21        // Down
22        if (i + 1 < m) {
23            auto [downMax, downMin] = solve(i + 1, j, grid);
24            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
25            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
26        }
27
28        // Right
29        if (j + 1 < n) {
30            auto [rightMax, rightMin] = solve(i, j + 1, grid);
31            maxVal =
32                max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
33            minVal =
34                min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
35        }
36
37        return t[i][j] = {maxVal, minVal};
38    }
39    int maxProductPath(vector<vector<int>>& grid) {
40        m = grid.size();
41        n = grid[0].size();
42
43        t = vector<vector<pair<ll, ll>>>(
44            m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
45        auto [maxProd, minProd] = solve(0, 0, grid);
46
47        return maxProd < 0 ? -1 : maxProd % MOD;
48    }
49};