class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt = 0;
        
        for (char p : s) {
            if (p == '(') {
                if (cnt > 0) {
                    ans += p;
                }
                cnt++;
            } else {
                cnt--;
                if (cnt > 0) {
                    ans += p;
                }
            }
        }
        
        return ans;
    }
};