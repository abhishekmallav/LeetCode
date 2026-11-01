1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int n = colors.size();
5
6        int result = 0;
7
8        for (int i = 0; i < n; i++) {
9            if (colors[i] != colors[0]) {
10                result = max(result, i);
11            }
12
13            if (colors[i] != colors[n - 1]) {
14                result = max(result, abs(i - (n - 1)));
15            }
16        }
17
18        return result;
19    }
20};