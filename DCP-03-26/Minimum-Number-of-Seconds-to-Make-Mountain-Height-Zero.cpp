1class Solution {
2public:
3    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
4        int maxTime = *max_element(workerTimes.begin(), workerTimes.end());
5
6        long long L = 1;
7        long long R = (long long)maxTime * mountainHeight * (mountainHeight + 1) / 2;
8        long long result = R;
9
10        while (L <= R) {
11            long long mid = L + (R - L) / 2;
12            long long height = 0;
13
14            for (int t : workerTimes) {
15                long long h = (sqrt(2.0 * (mid / t) + 0.25)) - 0.5 ;
16                height += h;
17
18                if (height >= mountainHeight)
19                    break;
20            }
21
22            if (height >= mountainHeight) {
23                result = mid;
24                R = mid - 1;
25            } else {
26                L = mid + 1;
27            }
28        }
29
30        return result;
31    }
32};