1class Solution {
2public:
3    int findContentChildren(vector<int>& g, vector<int>& s) {
4        sort(g.begin(), g.end());
5        sort(s.begin(), s.end());
6
7        int child = 0;
8        int cookie = 0;
9
10        while (child < g.size() && cookie < s.size()) {
11            if (s[cookie] >= g[child]) {
12                child++; 
13            }
14            cookie++;
15        }
16        return child;
17    }
18};