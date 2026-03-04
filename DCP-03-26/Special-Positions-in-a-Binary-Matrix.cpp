1class Solution {
2public:
3    int numSpecial(vector<vector<int>>& mat) {
4        int m = mat.size();
5        int n = mat[0].size();
6
7        vector<int> row(m, 0);
8        vector<int> col(n, 0);
9
10        for (int i = 0; i < m; i++) {
11            for (int j = 0; j < n; j++) {
12                row[i] += mat[i][j];
13                col[j] += mat[i][j];
14            }
15        }
16
17        int count = 0;
18
19        for (int i = 0; i < m; i++) {
20            for (int j = 0; j < n; j++) {
21                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
22                    count++;
23                }
24            }
25        }
26
27        return count;
28    }
29};