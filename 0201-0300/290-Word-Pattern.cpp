1class Solution {
2public:
3    bool wordPattern(string pattern, string s) {
4        istringstream iss(s);
5        string word;
6        vector<string> words;
7
8        while (iss >> word) {
9            words.push_back(word);
10        }
11
12        if (words.size() != pattern.size()) {
13            return false;
14        }
15
16        unordered_map<char, string> charToWord;
17        unordered_map<string, char> wordToChar;
18
19        for (int i = 0; i < pattern.size(); i++) {
20            char c = pattern[i];
21            string w = words[i];
22
23            if (charToWord.count(c) && charToWord[c] != w) {
24                return false;
25            }
26
27            if (wordToChar.count(w) && wordToChar[w] != c) {
28                return false;
29            }
30
31            charToWord[c] = w;
32            wordToChar[w] = c;
33        }
34
35        return true;
36    }
37};