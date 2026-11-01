class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();

        if (numRows == 1 || n <= numRows) {
            return s;
        }
        
        int maxCol = n;
        vector<vector<char>> grid(numRows, vector<char>(maxCol, '\0'));

        int k = 0; // Pointer for string s
        int j = 0; // Column pointer
        int i = 0; // Row pointer

        while (k < n) {
            for (i = 0; i < numRows && k < n; i++) {
                grid[i][j] = s[k++];
            }
            i = numRows - 2;
            j++;

            for (; i > 0 && k < n; i--) {
                grid[i][j++] = s[k++];
            }
        }

        string ans = "";
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < maxCol; col++) {
                if (grid[row][col] != '\0') {
                    ans += grid[row][col];
                }
            }
        }

        return ans;
    }
};