class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool squares[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '1';
                int squareIdx = (i / 3) * 3 + (j / 3);
                if (rows[i][num] || cols[j][num] || squares[squareIdx][num]) {
                    return false;
                }

                rows[i][num] = true;
                cols[j][num] = true;
                squares[squareIdx][num] = true;
            }
        }

        return true;
    }
};
