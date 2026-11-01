1class Solution {
2public:
3    bool hasAllCodes(string s, int k) {
4        int n = s.length();
5        unordered_set<string> st;
6        for (int i = k; i <= n; i++) {
7            st.insert(s.substr(i - k, k));
8        }
9        if (st.size() == pow(2, k)) {
10            return true;
11        }
12        return false;
13    }
14};