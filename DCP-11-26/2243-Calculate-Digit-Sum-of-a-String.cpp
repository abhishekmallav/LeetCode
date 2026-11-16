class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            int n = s.length();
            string tmp = "";
            for (int i = 0; i < n; i += k) {
                int sum = 0;
                for (int j = i; j < n && j < i + k; j++) {
                    sum += s[j] - '0';
                }
                tmp += to_string(sum);
            }
            s = tmp;
        }
        return s;
    }
};