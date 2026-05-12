1class Solution {
2public:
3    bool isPossible(vector<vector<int>>& tasks, int mid) {
4        for (auto& task : tasks) {
5            int actual = task[0];
6            int minimum = task[1];
7
8            if (minimum > mid) {
9                return false;
10            }
11
12            mid -= actual;
13        }
14
15        return true;
16    }
17
18    int minimumEffort(vector<vector<int>>& tasks) {
19        int n = tasks.size();
20
21        int l = 0;
22        int r = 1e9;
23
24        int result = INT_MAX;
25
26        auto lambda = [](auto& task1, auto& task2) {
27            int diff1 = task1[1] - task1[0];
28            int diff2 = task2[1] - task2[0];
29
30            return diff1 > diff2;
31        };
32
33        sort(begin(tasks), end(tasks), lambda);
34
35        while (l <= r) {
36            int mid = l + (r - l) / 2;
37
38            if (isPossible(tasks, mid)) {
39                result = mid;
40                r = mid - 1;
41            } else {
42                l = mid + 1;
43            }
44        }
45
46        return result;
47    }
48};