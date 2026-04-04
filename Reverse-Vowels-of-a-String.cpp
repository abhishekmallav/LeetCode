1class Solution {
2public:
3    bool isVowel(char c) {
4        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
5            c == 'E' || c == 'I' || c == 'O' || c == 'U') {
6            return true;
7        }
8        return false;
9    }
10    string reverseVowels(string s) {
11        int n = s.length();
12        vector<char> vowels;
13        vector<int> idx;
14        for (int i = 0; i < n; i++) {
15            if (isVowel(s[i])) {
16                vowels.push_back(s[i]);
17                idx.push_back(i);
18            }
19        }
20        reverse(vowels.begin(), vowels.end());
21        for (int i = 0; i < idx.size(); i++) {
22            s[idx[i]] = vowels[i];
23        }
24        return s;
25    }
26};