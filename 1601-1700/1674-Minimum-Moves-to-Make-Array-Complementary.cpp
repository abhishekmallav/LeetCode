1class Solution {
2public:
3    int minMoves(vector<int>& nums, int limit) {
4        int n = nums.size();
5
6        vector<int> diff(2 * limit + 2, 0);
7
8        for (int i = 0; i < n / 2; i++) {
9            int a = nums[i];
10            int b = nums[n - 1 - i];
11
12            int left = min(a, b) + 1;
13            int right = max(a, b) + limit;
14            diff[left] -= 1;
15            diff[right + 1] += 1;
16
17            diff[a + b] -= 1;
18            diff[a + b + 1] += 1;
19        }
20
21        int ans = n;
22        int curr = n;
23
24        for (int i = 2; i <= 2 * limit; i++) {
25            curr += diff[i];
26            ans = min(ans, curr);
27        }
28
29        return ans;
30    }
31};