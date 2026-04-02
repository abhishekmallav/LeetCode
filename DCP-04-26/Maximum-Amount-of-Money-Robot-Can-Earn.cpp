1class Solution {
2public:
3    int m;
4    int n;
5    int t[501][501][3];
6
7    int solve(vector<vector<int>>& coins, int i, int j, int neu) {
8        if(i == m-1 && j == n-1) {
9            if(coins[i][j] < 0 && neu > 0) {
10                return 0;
11            }
12
13            return coins[i][j];
14        }
15
16        if(i >= m || j >= n) {
17            return INT_MIN;
18        }
19
20        if(t[i][j][neu] != INT_MIN) {
21            return t[i][j][neu];
22        }
23
24        int take = coins[i][j] + max(solve(coins, i+1, j, neu), solve(coins, i, j+1, neu));
25
26        int skip = INT_MIN;
27        if(coins[i][j] < 0 && neu > 0) {
28            int skipDown = solve(coins, i+1, j, neu-1);
29            int skipRight = solve(coins, i, j+1, neu-1);
30
31            skip = max(skipDown, skipRight);
32        }
33
34        return t[i][j][neu] = max(take, skip);
35    }
36
37    int maximumAmount(vector<vector<int>>& coins) {
38
39        m = coins.size();
40        n = coins[0].size();
41
42        for(int i = 0; i < 501; i++) {
43            for(int j = 0; j < 501; j++) {
44                for(int k = 0; k < 3; k++) {
45                    t[i][j][k] = INT_MIN;
46                }
47            }
48        }
49
50        return solve(coins, 0, 0, 2);
51    }
52};
53