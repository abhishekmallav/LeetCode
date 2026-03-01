1class Solution {
2public:
3    int minPartitions(string n) {
4        char c = '0';
5        for (int i = 0; i < n.length(); i++) {
6            if (n[i] > c) {
7                c = n[i];
8            }
9        }
10        return c - '0';
11    }
12};