1class Solution {
2public:
3    int minFlips(string s) {
4        int n = s.length();
5        string str = s + s;
6        string s1, s2;
7
8        for (int i = 0; i < 2 * n; i++) {
9            // 010101...
10            s1 += (i % 2 ? '1' : '0'); 
11            // 101010...
12            s2 += (i % 2 ? '0' : '1'); 
13        }
14
15        int result = n;
16        int flip1 = 0;
17        int flip2 = 0;
18
19        int i = 0, j = 0;
20
21        while (j < 2 * n) {
22
23            if (str[j] != s1[j]) flip1++;
24            if (str[j] != s2[j]) flip2++;
25
26            if (j - i + 1 > n) {
27                if (str[i] != s1[i]) flip1--;
28                if (str[i] != s2[i]) flip2--;
29                i++;
30            }
31
32            if (j - i + 1 == n) {
33                result = min(result, min(flip1, flip2));
34            }
35
36            j++;
37        }
38
39        return result;
40    }
41};