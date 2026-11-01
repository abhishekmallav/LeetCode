1class Solution {
2public:
3    vector<int> getRow(int rowIndex) {
4        vector<int> ans;
5        // nC0 is always 1
6        long long current = 1;
7        ans.push_back((int)current);
8        
9        // Formula to get nCi from nC(i-1)
10        // Using long long to prevent overflow during multiplication
11        for (int i = 1; i <= rowIndex; i++) {
12            current = current * (rowIndex - i + 1) / i;
13            ans.push_back((int)current);
14        }
15        
16        return ans;
17    }
18};