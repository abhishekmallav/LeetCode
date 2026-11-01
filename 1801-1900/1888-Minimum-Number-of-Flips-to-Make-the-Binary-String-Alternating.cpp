1class Solution {
2public:
3    int minFlips(string s) {
4        int n = s.length();
5        // not using the extra s+s string and rotating using modulo %
6        // not using extra space for the pattern strings 010101... 101010...
7        // we know that cahracters are alternating so we can predict them by
8        // index even 0 odd 1 for S1 even 1 ood 0 for S2
9
10        int result = n;
11        int flip1 = 0;
12        int flip2 = 0;
13
14        int i = 0, j = 0;
15
16        while (j < 2 * n) {
17            char expectedS1 = (j % 2 ? '0' : '1');
18            char expectedS2 = (j % 2 ? '1' : '0');
19
20            if (s[j % n] != expectedS1)
21                flip1++;
22            if (s[j % n] != expectedS2)
23                flip2++;
24
25            if (j - i + 1 > n) {
26                expectedS1 = (i % 2 ? '0' : '1');
27                expectedS2 = (i % 2 ? '1' : '0');
28                if (s[i % n] != expectedS1)
29                    flip1--;
30                if (s[i % n] != expectedS2)
31                    flip2--;
32                i++;
33            }
34
35            if (j - i + 1 == n) {
36                result = min(result, min(flip1, flip2));
37            }
38
39            j++;
40        }
41
42        return result;
43    }
44};