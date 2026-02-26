1class Solution {
2public:
3    int numSteps(string s) {
4        int count = 0;
5
6        while (s != "1") {
7            if (s.back() == '0') {
8                // even divide by 2
9                s.pop_back();
10            } else {
11                // odd add 1
12                int i = s.size() - 1;
13                while (i >= 0 && s[i] == '1') {
14                    s[i] = '0';
15                    i--;
16                }
17
18                if (i >= 0) {
19                    s[i] = '1';
20                } else {
21                    s = '1' + s; 
22                }
23            }
24            count++;
25        }
26
27        return count;
28    }
29};