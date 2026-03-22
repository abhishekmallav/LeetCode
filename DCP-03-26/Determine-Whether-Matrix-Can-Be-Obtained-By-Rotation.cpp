1class Solution {
2public:
3    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
4        int n = mat.size();
5
6        for (int c = 1; c <= 4; c++) {
7
8            bool equal = true;
9            for (int i = 0; i < n; i++) {
10                for (int j = 0; j < n; j++) {
11                    if (mat[i][j] != target[i][j]) {
12                        equal = false;
13                        break;
14                    }
15                }
16                if (!equal)
17                    break;
18            }
19
20            if (equal)
21                return true;
22
23            for (int i = 0; i < n; i++) {
24                for (int j = i; j < n; j++) {
25                    swap(mat[i][j], mat[j][i]);
26                }
27            }
28
29            for (int i = 0; i < n; i++) {
30                reverse(mat[i].begin(), mat[i].end());
31            }
32        }
33
34        return false;
35    }
36};
37