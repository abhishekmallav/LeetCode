1class Solution {
2public:
3    vector<string> findWords(vector<string>& words) {
4        vector<string> ans;
5        set<char> first = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
6        set<char> second = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
7        set<char> third = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
8
9        int n = words.size();
10        for (int i = 0; i < n; i++) {
11
12            string s = words[i];
13            int m = s.length();
14            int cnt1 = 0;
15            int cnt2 = 0;
16            int cnt3 = 0;
17
18            for (int j = 0; j < m; j++) {
19                char ch = (char)tolower(s[j]);
20
21                auto it1 = first.find(ch);
22                if (it1 != first.end()) {
23                    cnt1++;
24                }
25
26                auto it2 = second.find(ch);
27                if (it2 != second.end()) {
28                    cnt2++;
29                }
30
31                auto it3 = third.find(ch);
32                if (it3 != third.end()) {
33                    cnt3++;
34                }
35            }
36            if (cnt1 == m || cnt2 == m || cnt3 == m) {
37                ans.push_back(words[i]);
38            }
39        }
40        return ans;
41    }
42};