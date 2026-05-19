class Solution {
public:
    bool checkRow(vector<vector<char>>& board, int rowIndex) {

        vector<bool> checkNum(9, false);
        for (int j = 0; j < 9; j++) {
            if (board[rowIndex][j] == '.') {
                continue;
            }
            int num = board[rowIndex][j] - '1';
            if (checkNum[num]) {
                return false;
            }
            checkNum[num] = true;
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& board, int colIndex) {
        vector<bool> checkNum(9, false);
        for (int i = 0; i < 9; i++) {
            if (board[i][colIndex] == '.') {
                continue;
            }
            int num = board[i][colIndex] - '1';
            if (checkNum[num]) {
                return false;
            }
            checkNum[num] = true;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        // solution 1: check for each row, grid and subgrid respectively

        int n = board.size();
        for (int i = 0; i < n; i++) {
            if (!checkRow(board, i)) {
                return false;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!checkCol(board, j)) {
                return false;
            }
        }
        // check grid code
        for (int i = 0; i < 9; i+= 3) {
            for (int j = 0 ; j < 9 ; j+=3) {
                
                vector<bool>checkNum(9, false);
                for(int k = i; k < i + 3; k++)
                {
                    for(int m = j ; m < j + 3 ; m++)
                    {
                        if (board[k][m] == '.') {
                            continue;
                        }
                        int num = board[k][m] - '1';
                        if (checkNum[num]) {
                            return false;
                        }
                        checkNum[num] = true;
                    }
                }
            }
        }
        return true;
    }
};