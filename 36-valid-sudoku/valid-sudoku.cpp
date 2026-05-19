class Solution {
public:
    // bool checkRow(vector<vector<char>>& board, int rowIndex) {

    //     vector<bool> checkNum(9, false);
    //     for (int j = 0; j < 9; j++) {
    //         if (board[rowIndex][j] == '.') {
    //             continue;
    //         }
    //         int num = board[rowIndex][j] - '1';
    //         if (checkNum[num]) {
    //             return false;
    //         }
    //         checkNum[num] = true;
    //     }
    //     return true;
    // }
    // bool checkCol(vector<vector<char>>& board, int colIndex) {
    //     vector<bool> checkNum(9, false);
    //     for (int i = 0; i < 9; i++) {
    //         if (board[i][colIndex] == '.') {
    //             continue;
    //         }
    //         int num = board[i][colIndex] - '1';
    //         if (checkNum[num]) {
    //             return false;
    //         }
    //         checkNum[num] = true;
    //     }
    //     return true;
    // }
    bool isValidSudoku(vector<vector<char>>& board) {

        // solution 1: check for each row, grid and subgrid respectively

        // int n = board.size();
        // for (int i = 0; i < n; i++) {
        //     if (!checkRow(board, i)) {
        //         return false;
        //     }
        // }
        // for (int j = 0; j < n; j++) {
        //     if (!checkCol(board, j)) {
        //         return false;
        //     }
        // }
        // // check grid code
        // for (int i = 0; i < 9; i+= 3) {
        //     for (int j = 0 ; j < 9 ; j+=3) {
                
        //         vector<bool>checkNum(9, false);
        //         for(int k = i; k < i + 3; k++)
        //         {
        //             for(int m = j ; m < j + 3 ; m++)
        //             {
        //                 if (board[k][m] == '.') {
        //                     continue;
        //                 }
        //                 int num = board[k][m] - '1';
        //                 if (checkNum[num]) {
        //                     return false;
        //                 }
        //                 checkNum[num] = true;
        //             }
        //         }
        //     }
        // }
        // return true;

        // Solution 2: uses Indexing
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool grids[9][9] = {false};


        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                int gridNum = (i / 3) * 3 + (j/3);
                if(rows[i][num] == true || cols[j][num] == true || grids[gridNum][num] == true)
                {
                    return false;
                }
                rows[i][num] = true; 
                cols[j][num] = true;
                grids[gridNum][num] = true;        
            }
        }
        return true;
    }
};