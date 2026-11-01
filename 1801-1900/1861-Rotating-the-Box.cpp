1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
4        int row = boxGrid.size();
5        int col = boxGrid[0].size();
6
7        for (int i = 0; i < row; i++) {
8            int k = col - 1; 
9            for (int j = col - 1; j >= 0; j--) {
10                if (boxGrid[i][j] == '*') {
11                    k = j - 1; 
12                } 
13                else if (boxGrid[i][j] == '#') {
14                    swap(boxGrid[i][j], boxGrid[i][k]);
15                    k--;
16                }
17            }
18        }
19
20        vector<vector<char>> grid(col, vector<char>(row));
21
22        for (int i = 0; i < row; i++) {
23            for (int j = 0; j < col; j++) {
24                grid[j][row - 1 - i] = boxGrid[i][j];
25            }
26        }
27        
28        return grid;
29    }
30};