1class Solution {
2public:
3    typedef long long ll;
4
5    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
6        int MOD = 12345;
7        int row = grid.size();
8        int col = grid[0].size();
9
10        ll prefixProduct = 1;
11        ll suffixProduct = 1;
12
13        vector<vector<ll>> prefix(row, vector<ll>(col, 1));
14        vector<vector<ll>> suffix(row, vector<ll>(col, 1));
15        vector<vector<int>> ans(row, vector<int>(col, 1));
16
17        // prefix product
18        for (int i = 0; i < row; i++) {
19            for (int j = 0; j < col; j++) {
20                prefix[i][j] = prefixProduct;
21                prefixProduct = (prefixProduct * grid[i][j]) % MOD;
22            }
23        }
24
25        // suffix product
26        for (int i = row - 1; i >= 0; i--) {
27            for (int j = col - 1; j >= 0; j--) {
28                suffix[i][j] = suffixProduct;
29                suffixProduct = (suffixProduct * grid[i][j]) % MOD;
30            }
31        }
32
33        // prefixProduct[i][j]*suffixProduct[i][j]=ans[i][j]
34        for (int i = 0; i < row; i++) {
35            for (int j = 0; j < col; j++) {
36                ans[i][j] = (int)(prefix[i][j] * suffix[i][j]) % MOD;
37            }
38        }
39        return ans;
40    }
41};