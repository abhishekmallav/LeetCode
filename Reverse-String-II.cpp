1class Solution {
2public:
3    string reverseStr(string s, int k) {
4        int n = s.length();
5        int L = 0;
6        int R = min(L + k - 1, n - 1);
7        int pos = 2 * k;
8
9        while (L < n) {
10            while (L < R) {
11                swap(s[L], s[R]);
12                L++;
13                R--;
14            }
15            L = pos;
16            R = min(L + k - 1, n - 1);
17            pos += 2 * k;
18        }
19        return s;
20    }
21};