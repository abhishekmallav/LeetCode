1class Solution {
2public:
3    vector<bool> isPrime;
4
5    void buildSieve(int maxEl) {
6        isPrime.resize(maxEl + 1, true);
7
8        isPrime[0] = false;
9        isPrime[1] = false;
10
11        for (int num = 2; num * num <= maxEl; num++) {
12            if (isPrime[num]) {
13
14                for (int multiple = num * num; multiple <= maxEl;
15                     multiple += num) {
16                    isPrime[multiple] = false;
17                }
18            }
19        }
20    }
21
22    int minJumps(vector<int>& nums) {
23        int n = nums.size();
24
25        unordered_map<int, vector<int>> mp;
26        int maxEl = 0;
27        for (int i = 0; i < n; i++) {
28            mp[nums[i]].push_back(i);
29            maxEl = max(maxEl, nums[i]);
30        }
31
32        buildSieve(maxEl);
33
34        queue<int> que;
35        vector<bool> visited(n, false);
36        que.push(0);
37        visited[0] = true;
38
39        unordered_set<int> seen;
40
41        int steps = 0;
42        while (!que.empty()) {
43            int size = que.size();
44
45            while (size--) {
46                int i = que.front();
47                que.pop();
48
49                if (i == n - 1) {
50                    return steps;
51                }
52
53                if (i - 1 >= 0 && !visited[i - 1]) {
54                    que.push(i - 1);
55                    visited[i - 1] = true;
56                }
57
58                if (i + 1 <= n - 1 && !visited[i + 1]) {
59                    que.push(i + 1);
60                    visited[i + 1] = true;
61                }
62
63                if (!isPrime[nums[i]] || seen.count(nums[i])) {
64                    continue;
65                }
66
67                for (int multiple = nums[i]; multiple <= maxEl;
68                     multiple += nums[i]) {
69                    if (!mp.contains(multiple)) {
70                        continue;
71                    }
72
73                    for (int& j : mp[multiple]) {
74                        if (!visited[j]) {
75                            que.push(j);
76                            visited[j] = true;
77                        }
78                    }
79                }
80
81                seen.insert(nums[i]);
82            }
83
84            steps++;
85        }
86
87        return steps;
88    }
89};
90