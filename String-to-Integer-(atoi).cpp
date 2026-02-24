1class Solution {
2public:
3    int myAtoi(string s) {
4        int i = 0;
5        int n = s.length();
6        
7        while (i < n && s[i] == ' ') {
8            i++;
9        }
10
11        int sign = 1;
12        if (i < n && (s[i] == '+' || s[i] == '-')) {
13            if (s[i] == '-') {
14                sign = -1;
15            }
16            i++;
17        }
18        
19        long result = 0;
20        
21        while (i < n && s[i]>=48 && s[i]<=57) {
22            result = result * 10 + (s[i] - 48);
23            
24            if (sign * result > INT_MAX)
25                return INT_MAX;
26            if (sign * result < INT_MIN)
27                return INT_MIN;
28            
29            i++;
30        }
31        
32        return sign * result;
33    }
34};