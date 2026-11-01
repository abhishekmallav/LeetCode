1class Solution {
2public:
3    void solve(int n, string& curr, int& count, int k, string& result) {
4        if (curr.length() == n) {
5            count++;
6            if (count == k) {
7                result = curr;
8            }
9            return;
10        }
11
12        for (char ch = 'a'; ch <= 'c'; ch++) {
13            if (!curr.empty() && curr.back() == ch) {
14                continue;
15            }
16
17            curr.push_back(ch);
18
19            solve(n, curr, count, k, result);
20
21            if (!result.empty())
22                return;
23            curr.pop_back();
24        }
25    }
26
27    string getHappyString(int n, int k) {
28        string curr = "";
29        string result = "";
30        int count = 0;
31
32        solve(n, curr, count, k, result);
33
34        return result;
35    }
36};