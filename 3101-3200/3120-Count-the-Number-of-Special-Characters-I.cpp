class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower[26] = {0};
        int upper[26] = {0};

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (ch >= 'a' && ch <= 'z') {
                lower[ch - 'a']++;
            }
            if (ch >= 'A' && ch <= 'Z') {
                upper[ch - 'A']++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] >= 1 && upper[i] >= 1)
                cnt++;
        }
        return cnt;
    }
};