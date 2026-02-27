1class Solution {
2public:
3    int minOperations(string s, int k) {
4        int n = s.length();
5        vector<int> operations(n + 1, -1);
6        queue<int> que;
7        int startZeros = 0;
8
9        for (char& ch : s) {
10            if (ch == '0') {
11                startZeros++;
12            }
13        }
14
15        if (startZeros == 0) {
16            return 0;
17        }
18
19        set<int> evenSet;
20        set<int> oddSet;
21
22        for (int cnt = 0; cnt <= n; cnt++) {
23            if (cnt % 2 == 0) {
24                evenSet.insert(cnt);
25            } else {
26                oddSet.insert(cnt);
27            }
28        }
29        que.push(startZeros);
30        operations[startZeros] = 0;
31        if (startZeros % 2 == 0) {
32            evenSet.erase(startZeros);
33        } else {
34            oddSet.erase(startZeros);
35        }
36        while (!que.empty()) {
37            int z = que.front();
38            que.pop();
39
40            int min_newZ = z + k - 2 * min(k, z);
41            int max_newZ = z + k - 2 * max(0, k - n + z);
42
43            set<int>& currSet = (min_newZ % 2 == 0) ? evenSet : oddSet;
44            auto it = currSet.lower_bound(min_newZ);
45
46            while (it != currSet.end() && *it <= max_newZ) {
47                int newZ = *it;
48
49                if (operations[newZ] == -1) {
50                    operations[newZ] = operations[z] + 1;
51                    if (newZ == 0) {
52                        return operations[newZ];
53                    }
54                    que.push(newZ);
55                }
56                it = currSet.erase(it);
57            }
58        }
59        return -1;
60    }
61};