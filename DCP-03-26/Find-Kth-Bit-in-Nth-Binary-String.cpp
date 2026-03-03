1class Solution {
2public:
3    string invert(string s) {
4        for (char& c : s) {
5            c = (c == '0' ? '1' : '0');
6        }
7        return s;
8    }
9    char findKthBit(int n, int k) {
10        string s = "0";
11        for (int i = 2; i <= n; i++) {
12            string prev = s;
13            string sub = invert(prev);
14            reverse(sub.begin(), sub.end());
15            s = prev + "1" + sub;
16        }
17
18        return s[k-1];
19    }
20};