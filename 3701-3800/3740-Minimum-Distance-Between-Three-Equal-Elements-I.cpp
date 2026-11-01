1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        int n = nums.size(), mini = 1e9;
5
6        for (int i = 0; i < n - 2; i++) {
7            for (int j = i + 1; j < n - 1; j++) {
8                for (int k = j + 1; k < n; k++) {
9                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
10                        int dist = abs(i - j) + abs(j - k) + abs(k - i);
11                        mini = min(mini, dist);
12                    }
13                }
14            }
15        }
16
17        return mini == 1e9 ? -1 : mini;
18    }
19};