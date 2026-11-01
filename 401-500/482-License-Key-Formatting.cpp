1class Solution {
2public:
3    string licenseKeyFormatting(string s, int k) {
4        string ans = "";
5        int count = 0;
6
7        for (int i = s.length() - 1; i >= 0; i--) {
8            if (s[i] != '-') {
9
10                if (count > 0 && count % k == 0) {
11                    ans += '-';
12                }
13
14                ans += toupper(s[i]);
15                count++;
16            }
17        }
18
19        reverse(ans.begin(), ans.end());
20        return ans;
21    }
22};