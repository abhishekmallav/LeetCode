1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        int n = matrix[0].size();
5        for (int i = 0; i < n; i++) {
6            for (int j = i + 1; j < n; j++) {
7                swap(matrix[i][j], matrix[j][i]);
8            }
9        }
10        for (int i = 0; i < n; i++) {
11            reverse(matrix[i].begin(), matrix[i].end());
12        }
13    }
14};