1class Solution {
2public:
3    vector<string> findOcurrences(string text, string first, string second) {
4        vector<string> ans;
5        vector<string> words;
6        istringstream iss(text);
7        string word;
8
9        while (iss >> word) {
10            words.push_back(word);
11        }
12        for (int i = 0; i < words.size() - 2; i++) {
13            if (words[i] == first && words[i + 1] == second) {
14                ans.push_back(words[i + 2]);
15            }
16        }
17        return ans;
18    }
19};