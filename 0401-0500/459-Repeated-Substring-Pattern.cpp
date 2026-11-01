1class Solution {
2public:
3    bool repeatedSubstringPattern(string s) {
4        int n = s.length();
5        
6        for (int len = 1; len <= n / 2; len++) {
7            if (n % len == 0) {
8
9                string sub = s.substr(0, len);
10                string reconstructed = "";
11                
12                int multiple = n / len;
13                for (int k = 0; k < multiple; k++) {
14                    reconstructed += sub;
15                }
16                
17                if (reconstructed == s) {
18                    return true;
19                }
20            }
21        }
22        
23        return false;
24    }
25};