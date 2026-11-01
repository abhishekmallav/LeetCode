1class Solution {
2public:
3    bool areSimilar(vector<vector<int>>& mat, int k) {
4        int m = mat.size();
5        int n = mat[0].size();
6        k = k % n;
7        for (int i = 0; i < m; i++) {
8            for (int j = 0; j < n; j++) {
9                int newIndex;
10
11                // we are not actually shifting the elements but comparing the
12                // new index if arr size is 3 and we have to rotate it 6 times
13                // we dont need to rotate it at all
14                // just check if the new index value with curr index
15
16                if (i % 2 == 0) {
17                    // left shift
18                    newIndex = (j + k) % n;
19                } else {
20                    // right shift
21                    newIndex = (j - k + n) % n;
22                }
23
24                if (mat[i][j] != mat[i][newIndex]) {
25                    return false;
26                }
27            }
28        }
29        return true;
30    }
31};
32