class Solution {
public:

    void setRowZero(vector<vector<int>>& matrix, int row)
    {
        for(int j = 0 ; j < matrix[0].size() ; j++)
        {
            matrix[row][j] = 0;
        }
    }
    void setColZero(vector<vector<int>>& matrix, int col)
    {
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            matrix[i][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {

        bool cornerZero = false;
        bool rowZero = false;
        bool colZero = false;
        if(matrix[0][0] == 0)
        {
            cornerZero = true;
        }
            for(int j = 0 ; j < matrix[0].size() ; j++)
            {
                if(matrix[0][j] == 0){
                    rowZero = true;
                }
            }
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            if(matrix[i][0] == 0){
                colZero = true;
            }
        }
        for(int i = 1 ; i < matrix.size() ; i++)
        {
            for(int j = 1 ; j < matrix[0].size() ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int j = 1 ; j < matrix[0].size(); j++)
        {
            if(matrix[0][j] == 0){
                setColZero(matrix, j);
            }
        }
        for(int i = 1 ; i < matrix.size(); i++)
        {
            if(matrix[i][0] == 0){
                setRowZero(matrix, i);
            }
        }
            if(rowZero)
            {
                setRowZero(matrix, 0);
            }
            if(colZero)
            {
                setColZero(matrix, 0);
            }
    }
};