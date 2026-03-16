1class Solution {
2public:
3    vector<int> getBiggestThree(vector<vector<int>>& grid) {
4        int n = grid.size(), m = grid[0].size();
5
6        vector<vector<int>> d1(n, vector<int>(m));
7        vector<vector<int>> d2(n, vector<int>(m));
8
9        // build diagonal prefix sums
10        for (int i = 0; i < n; i++) {
11            for (int j = 0; j < m; j++) {
12                d1[i][j] = grid[i][j];
13                if (i > 0 && j > 0)
14                    d1[i][j] += d1[i - 1][j - 1];
15
16                d2[i][j] = grid[i][j];
17                if (i > 0 && j + 1 < m)
18                    d2[i][j] += d2[i - 1][j + 1];
19            }
20        }
21
22        set<int> best;
23
24        for (int i = 0; i < n; i++) {
25            for (int j = 0; j < m; j++) {
26
27                best.insert(grid[i][j]);
28
29                for (int k = 1;; k++) {
30
31                    int top = i - k;
32                    int bottom = i + k;
33                    int left = j - k;
34                    int right = j + k;
35
36                    if (top < 0 || bottom >= n || left < 0 || right >= m)
37                        break;
38
39                    int sum = 0;
40
41                    // top -> right (D1)
42                    sum += d1[i][right];
43                    if (top - 1 >= 0 && j - 1 >= 0)
44                        sum -= d1[top - 1][j - 1];
45
46                    // right -> bottom (D2)
47                    sum += d2[bottom][j];
48                    if (i - 1 >= 0 && right + 1 < m)
49                        sum -= d2[i - 1][right + 1];
50
51                    // bottom -> left (D1)
52                    sum += d1[bottom][j];
53                    if (i - 1 >= 0 && left - 1 >= 0)
54                        sum -= d1[i - 1][left - 1];
55
56                    // left -> top (D2)
57                    sum += d2[i][left];
58                    if (top - 1 >= 0 && j + 1 < m)
59                        sum -= d2[top - 1][j + 1];
60
61                    // subtract corners counted twice
62                    sum -= grid[top][j];
63                    sum -= grid[i][right];
64                    sum -= grid[bottom][j];
65                    sum -= grid[i][left];
66
67                    best.insert(sum);
68                    if (best.size() < 3) {
69                        best.insert(sum);
70                    } else if (sum > *best.begin()) {
71                        best.insert(sum);
72                        best.erase(best.begin());
73                    }
74                }
75            }
76        }
77        vector<int> ans;
78        int cnt = 0;
79        for (auto it = best.rbegin(); it != best.rend() && cnt < 3;
80             ++it, ++cnt) {
81            ans.push_back(*it);
82        }
83        return ans;
84    }
85};