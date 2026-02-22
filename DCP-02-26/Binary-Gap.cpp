1class Solution {
2public:
3    int binaryGap(int n) {
4        // conversion of int to 32 bit binary representation string
5        string s = bitset<32>(n).to_string();
6        int i = 0;
7        int j = 0;
8        int result = INT_MIN;
9
10        while (j < s.length()) {
11            if (s[j] == '1') {
12                // check for the first '1'
13                if (i == 0) {
14                    i = j;
15                }
16                result = max(result, j - i);
17                i = j;
18                j++;
19                continue;
20            }
21            j++;
22        }
23        return result;
24    }
25};