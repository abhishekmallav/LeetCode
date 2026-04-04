1class Solution {
2public:
3    string multiply(string num1, string num2) {
4        if (num1 == "0" || num2 == "0") return "0";
5
6        int n = num1.size();
7        int m = num2.size();
8
9        vector<int> res(n + m, 0);
10
11
12        for (int i = n - 1; i >= 0; i--) {
13            for (int j = m - 1; j >= 0; j--) {
14
15                int mul = (num1[i] - '0') * (num2[j] - '0');
16                int sum = mul + res[i + j + 1];
17
18                res[i + j + 1] = sum % 10;
19                res[i + j] += sum / 10; 
20            }
21        }
22
23        string ans = "";
24        for (int digit : res) {
25            if (!(ans.empty() && digit == 0)) {
26                ans.push_back(digit + '0');
27            }
28        }
29
30        return ans.empty() ? "0" : ans;
31    }
32};