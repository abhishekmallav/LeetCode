1class Solution {
2public:
3    string decodeCiphertext(string encodedText, int rows) {
4        if (rows == 0) {
5            return "";
6        }
7
8        int n = encodedText.length();
9        int col = n / rows;
10
11        string str = "";
12
13        for (int i = 0; i < col; i++) {
14            str += encodedText[i];
15            int j = i + col + 1;
16            while (j < n) {
17                str += encodedText[j];
18                j += col + 1;
19            }
20        }
21        while (!str.empty() && str.back() == ' ') {
22            str.pop_back();
23        }
24        return str;
25    }
26};