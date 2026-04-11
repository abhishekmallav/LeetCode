1class Solution {
2public:
3    string convertToBase7(int num) {
4        if (num == 0) {
5            return "0";
6        }
7
8        string sign;
9        string ans = "";
10
11        if (num < 0) {
12            sign = "-";
13        } else {
14            sign = "";
15        }
16
17        while (num != 0) {
18            num = abs(num);
19            int bit = num % 7;
20            ans += to_string(bit);
21            num /= 7;
22        }
23
24        ans += sign;
25        reverse(ans.begin(), ans.end());
26        
27        return ans;
28    }
29};