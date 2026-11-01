1class Solution {
2public:
3    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
4                                         int y, int k) {
5        vector<vector<int>> ans = grid;
6        int L = x;
7        int R = x + k - 1;
8        while (L < R) {
9            for (int i = y; i < y + k; i++) {
10                swap(ans[L][i], ans[R][i]);
11            }
12            L++;
13            R--;
14        }
15        return ans;
16    }
17};