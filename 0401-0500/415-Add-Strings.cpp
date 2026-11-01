1class Solution {
2public:
3    string addStrings(string num1, string num2) {
4        string ans = "";
5        int i = num1.length() - 1;
6        int j = num2.length() - 1;
7        int carry = 0;
8
9        while (i >= 0 || j >= 0 || carry > 0) {
10            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
11            int digit2 = (j >= 0) ? num2[j] - '0' : 0;
12
13            int sum = digit1 + digit2 + carry;
14            ans.push_back((sum % 10) + '0');
15            carry = sum / 10;
16
17            i--;
18            j--;
19        }
20        reverse(ans.begin(), ans.end());
21        return ans;
22    }
23};