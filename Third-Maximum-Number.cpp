1class Solution {
2public:
3    int thirdMax(vector<int>& nums) {
4        int n = nums.size();
5        long long first = LLONG_MIN;
6        long long second = LLONG_MIN;
7        long long third = LLONG_MIN;
8
9        for (int i = 0; i < n; i++) {
10            //skipping the duplicates
11            if (nums[i] == first || nums[i] == second || nums[i] == third) {
12                continue;
13            }
14
15            if (nums[i] > first) {
16                third = second;
17                second = first;
18                first = nums[i];
19
20            } else if (nums[i] > second) {
21                third = second;
22                second = nums[i];
23
24            } else if (nums[i] > third) {
25                third = nums[i];
26            }
27        }
28
29        if (third == LLONG_MIN) {
30            return first;
31        }
32
33        return third;
34    }
35};