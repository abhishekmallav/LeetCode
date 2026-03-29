1class Solution {
2public:
3    bool canBeEqual(string s1, string s2) {
4        if (s1 == s2) {
5            return true;
6        }
7        string tmp = s1;
8        swap(tmp[0], tmp[2]);
9        if (tmp == s2) {
10            return true;
11        }
12        swap(tmp[1], tmp[3]);
13        if (tmp == s2) {
14            return true;
15        }
16        swap(s1[1], s1[3]);
17        if (s1 == s2) {
18            return true;
19        }
20        return false;
21    }
22};