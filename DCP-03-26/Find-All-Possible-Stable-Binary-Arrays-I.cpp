1class Solution {
2public:
3    int M = 1e9 + 7;
4    int t[201][201][2];
5
6    int solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit) {
7        if(onesLeft == 0 && zerosLeft == 0) {
8            return 1;
9        }
10
11        if(t[onesLeft][zerosLeft][lastWasOne] != -1) {
12            return t[onesLeft][zerosLeft][lastWasOne];
13        }
14
15
16        int result = 0;
17
18        if(lastWasOne == true) { //explore 0s
19            for(int len = 1; len <= min(zerosLeft, limit); len++) {
20                result = (result + solve(onesLeft, zerosLeft - len, false, limit)) % M;
21            }
22        } else { //explore 1s
23            for(int len = 1; len <= min(onesLeft, limit); len++) {
24                result = (result + solve(onesLeft - len, zerosLeft, true, limit)) % M;
25            }
26        }
27
28        return t[onesLeft][zerosLeft][lastWasOne] = result;
29
30    }
31
32    int numberOfStableArrays(int zero, int one, int limit) {
33        memset(t, -1, sizeof(t));
34        int startWithOne = solve(one, zero, false, limit);
35        int startWithZero = solve(one, zero, true, limit);
36
37        return (startWithOne + startWithZero) % M;
38
39    }
40};
41