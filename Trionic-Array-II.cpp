1class Solution {
2public:
3    long long maxSumTrionic(vector<int>& nums) {
4        int n = nums.size();
5        long long ans = LLONG_MIN;
6
7        for (int i = 0; i < n; i++) {
8            int j = i;
9            int p, q, k;
10            long long res = 0;
11            long long sum = 0, max_sum = 0;
12
13            // First increasing phase
14            while (j + 1 < n && nums[j] < nums[j + 1]) {
15                j++;
16            }
17            p = j;
18            if (p == i) continue;
19
20            // Add peak and previous
21            res += nums[p] + nums[p - 1];
22
23            // Decreasing phase
24            while (j + 1 < n && nums[j] > nums[j + 1]) {
25                j++;
26                res += nums[j];
27            }
28            q = j;
29
30            // Validate third phase existence
31            if (q == p || q + 1 >= n || nums[q] >= nums[q + 1]) {
32                i = q;
33                continue;
34            }
35
36            // Start final increasing phase
37            res += nums[q + 1];
38
39            // Extend final increasing (right side)
40            sum = 0;
41            max_sum = 0;
42            k = q + 2;
43            while (k < n && nums[k] > nums[k - 1]) {
44                sum += nums[k];
45                max_sum = max(max_sum, sum);
46                k++;
47            }
48            res += max_sum;
49
50            // Extend first increasing backwards (left side)
51            sum = 0;
52            max_sum = 0;
53            k = p - 2;
54            while (k >= i) {
55                sum += nums[k];
56                max_sum = max(max_sum, sum);
57                k--;
58            }
59            res += max_sum;
60            ans = max(ans, res);
61
62            // Skip processed region
63            i = q - 1;
64        }
65
66        return ans;
67    }
68};
69