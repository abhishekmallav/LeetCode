class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> status(26, 0);
        vector<bool> lower(26, false);

        int cnt = 0;

        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                int idx = ch - 'a';
                lower[idx] = true;

                if (status[idx] == 1) {
                    status[idx] = -1;
                    cnt--;
                }
            } else if (ch >= 'A' && ch <= 'Z') {
                int idx = ch - 'A';
                if (lower[idx] && status[idx] == 0) {
                    status[idx] = 1;
                    cnt++;
                }
                if (!lower[idx] && status[idx] == 0) {
                    status[idx] = -1;
                }
            }
        }

        return cnt;
    }
};