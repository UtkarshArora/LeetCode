class Solution {
public:
    bool checkRow(vector<char>&row)
    {
        vector<int>countArr(10);
        for(int j = 0 ; j < 9; j++)
        {
            int index = row[j] - '0';
            if(index>=1 && index<=9){
                countArr[index]++;
            if(countArr[index]>1)
                return false;
            }
            else
                continue;
        }
        return true;
    }
    bool checkCol(vector<vector<char>>&board, int j)
    {
        vector<int>countArr(10);
        for(int i = 0 ; i < 9; i++)
        {
            int index = board[i][j] - '0';
            if(index>=1 && index<=9){
                countArr[index]++;
            if(countArr[index]>1)
                return false;
            }
            else
                continue;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0 ; i < 9 ; i++)
        {
            if(!checkRow(board[i]))
                return false;
        }
        for(int j = 0 ; j < 9 ; j++)
        {
            if(!checkCol(board, j))
                return false;
        }
        for(int i = 0 ; i < 9 ; i=i+3)
        {
            for(int j = 0 ; j < 9 ; j = j + 3)
            {
            vector<int>countArr(10,0);
            for(int k = i ; k < i+3 ; k++)
            {
                for(int l = j ; l < j+3 ; l++)
                {
                    int index = board[k][l] - '0';
                    if(index>=1 && index<=9){
                        countArr[index]++;
                    if(countArr[index]>1)
                        return false;
                    }
                    else
                        continue;
                }
             }
            }
        }
        return true;
    }
};