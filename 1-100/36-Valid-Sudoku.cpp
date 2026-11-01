class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_set<char> box;

                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        char curr = board[i + k][j + l];

                        if (curr != '.') {
                            if (box.find(curr) != box.end()) {
                                return false;
                            }
                            box.insert(curr);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            unordered_set<char> row;
            unordered_set<char> col;

            for (int j = 0; j < 9; j++) {

                if (board[i][j] != '.') {
                    if (row.find(board[i][j]) != row.end()) {
                        return false;
                    }
                    row.insert(board[i][j]);
                }

                if (board[j][i] != '.') {
                    if (col.find(board[j][i]) != col.end()) {
                        return false;
                    }
                    col.insert(board[j][i]);
                }
            }
        }

        return true;
    }
};
