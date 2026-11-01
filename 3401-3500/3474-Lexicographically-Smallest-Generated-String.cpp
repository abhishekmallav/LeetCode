1class Solution {
2public:
3    bool isSame(string& word, string& str2, int i, int m) {
4        for (int j = 0; j < m; j++) {
5            if (word[i] != str2[j]) {
6                return false;
7            }
8            i++;
9        }
10        return true;
11    }
12
13    string generateString(string str1, string str2) {
14        int n = str1.length();
15        int m = str2.length();
16
17        int N = n + m - 1;
18        string word(N, '$');
19
20        vector<bool> canChange(N, false);
21
22        for (int i = 0; i < n; i++) {
23            if (str1[i] == 'T') {
24                int j = i;
25                for (int k = 0; k < m; k++) {
26                    if (word[j] != '$' && word[j] != str2[k]) {
27                        return "";
28                    }
29                    word[j] = str2[k];
30                    j++;
31                }
32            }
33        }
34
35        for (int i = 0; i < N; i++) {
36            if (word[i] == '$') {
37                word[i] = 'a';
38                canChange[i] = true;
39            }
40        }
41
42        for (int i = 0; i < n; i++) {
43            if (str1[i] == 'F') {
44
45                if (isSame(word, str2, i, m)) {
46
47                    bool changed = false;
48                    for (int k = i + m - 1; k >= i; k--) {
49                        if (canChange[k] == true) {
50                            word[k] = 'b';
51                            changed = true;
52                            break;
53                        }
54                    }
55
56                    if (changed == false) {
57                        return "";
58                    }
59                }
60            }
61        }
62
63        return word;
64    }
65};
66