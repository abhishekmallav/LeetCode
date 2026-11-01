1class Solution {
2public:
3    string defangIPaddr(string address) {
4        string ans;
5
6        for (char c : address) {
7            if (c == '.') {
8                ans += "[.]";
9            } else {
10                ans += c;
11            }
12        }
13
14        return ans;
15    }
16};