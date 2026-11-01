1class Solution {
2public:
3    int closestTarget(vector<string>& words, string target, int startIndex) {
4        int n      = words.size();
5        int result = INT_MAX;
6
7        for (int i = 0; i < n; ++i) {
8            if (words[i] == target) {
9                int straightDist  = abs(i - startIndex);
10                int circularDist  = n-straightDist;
11
12                result = min({result, straightDist, circularDist});
13            }
14        }
15
16        return result == INT_MAX ? -1 : result;
17    }
18};
19