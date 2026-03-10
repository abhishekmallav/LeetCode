1class Solution {
2public:
3    int M = 1e9 + 7;
4    vector<vector<vector<int>>> t;
5
6    int solve(int i, int j, int last, int limit) {
7
8        // Base: no elements
9        if (i == 0 && j == 0)
10            return 0;
11
12        // Base: only zeros left
13        if (j == 0) {
14            if (last == 1)
15                return 0;
16            return (i <= limit) ? 1 : 0;
17        }
18
19        // Base: only ones left
20        if (i == 0) {
21            if (last == 0)
22                return 0;
23            return (j <= limit) ? 1 : 0;
24        }
25
26        if (t[i][j][last] != -1)
27            return t[i][j][last];
28
29        int result = 0;
30
31        if (last == 0) {
32            result =
33                (solve(i - 1, j, 0, limit) + solve(i - 1, j, 1, limit)) % M;
34
35            if (i - 1 >= limit)
36                result = (result - solve(i - 1 - limit, j, 1, limit) + M) % M;
37
38        } else {
39            result =
40                (solve(i, j - 1, 0, limit) + solve(i, j - 1, 1, limit)) % M;
41
42            if (j - 1 >= limit)
43                result = (result - solve(i, j - 1 - limit, 0, limit) + M) % M;
44        }
45
46        return t[i][j][last] = result;
47    }
48
49    int numberOfStableArrays(int zero, int one, int limit) {
50
51        t.assign(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));
52
53        return (solve(zero, one, 0, limit) + solve(zero, one, 1, limit)) % M;
54    }
55};