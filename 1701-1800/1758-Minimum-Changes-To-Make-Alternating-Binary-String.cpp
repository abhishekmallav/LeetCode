1class Solution {
2public:
3    int minOperations(string s) {
4        string copy0 = s;
5        string copy1 = s;
6
7        int n = s.length();
8
9        int cnt = 0;
10        int cnt0 = 1;
11        int cnt1 = 1;
12
13        for (int i = 1; i < n; i++) {
14            if (s[i] != s[i - 1]) {
15                continue;
16            }
17            if (s[i] == '0') {
18                s[i] = '1';
19            } else {
20                s[i] = '0';
21            }
22            cnt++;
23        }
24        copy0[0] = '0';
25        for (int i = 1; i < n; i++) {
26            if (copy0[i] != copy0[i - 1]) {
27                continue;
28            }
29            if (copy0[i] == '0') {
30                copy0[i] = '1';
31            } else {
32                copy0[i] = '0';
33            }
34            cnt0++;
35        }
36        copy1[0] = '1';
37        for (int i = 1; i < n; i++) {
38            if (copy1[i] != copy1[i - 1]) {
39                continue;
40            }
41            if (copy1[i] == '0') {
42                copy1[i] = '1';
43            } else {
44                copy1[i] = '0';
45            }
46            cnt1++;
47        }
48        return min(cnt, min(cnt0, cnt1));
49    }
50};