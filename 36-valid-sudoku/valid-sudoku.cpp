class Solution {
public:
    bool checkValid(char ch, vector<int>& countChar) {
        if (ch == '.')
            return true;
        int idx = ch - '0';
        if (idx < 0 || idx > 9)
            return false;
        countChar[idx]++;
        return countChar[idx] == 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            vector<char> row = board[i];
            vector<int> countChar(10);
            for (char ch : row) {
                if (!checkValid(ch, countChar))
                    return false;
            }
        }
        for (int j = 0; j < 9; j++) {
            vector<int> countChar(10);
            for (int i = 0; i < 9; i++) {
                char ch = board[i][j];
                if (!checkValid(ch, countChar))
                    return false;
            }
        }
        for (int i = 0; i < 9; i = i + 3) {
            for (int j = 0; j < 9; j = j + 3) {
                vector<int> countChar(10);
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        char ch = board[k][l];
                        if (!checkValid(ch, countChar))
                            return false;
                    }
                }
            }
        }
        return true;
    }
};