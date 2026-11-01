1class Solution {
2public:
3    int solve_BFS(vector<int>& arr, int& n) {
4        vector<bool> visited(n, false);
5        unordered_map<int, vector<int>> mp;
6        for (int i = 0; i < n; i++) {
7            mp[arr[i]].push_back(i);
8        }
9
10        queue<int> que;
11        que.push(0);
12        visited[0] = true;
13        int steps = 0;
14
15        while (!que.empty()) {
16            int size = que.size();
17
18            while (size--) {
19                int curr = que.front();
20                que.pop();
21
22                if (curr == n - 1) {
23                    return steps;
24                }
25
26                int left = curr - 1;
27                int right = curr + 1;
28
29                if (left >= 0 && !visited[left]) {
30                    que.push(left);
31                    visited[left] = true;
32                }
33
34                if (right < n && !visited[right]) {
35                    que.push(right);
36                    visited[right] = true;
37                }
38
39                for (const int& idx : mp[arr[curr]]) {
40                    if (!visited[idx]) {
41                        que.push(idx);
42                        visited[idx] = true;
43                    }
44                }
45
46                mp.erase(arr[curr]);
47            }
48            steps++;
49        }
50
51        return -1;
52    }
53    int minJumps(vector<int>& arr) {
54        int n = arr.size();
55        if (n == 1)
56            return 0;
57        return solve_BFS(arr, n);
58    }
59};
60