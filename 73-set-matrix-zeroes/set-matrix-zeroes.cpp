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
        vector<int>rows;
        vector<int>cols;

        for(int i = 0 ; i < matrix.size() ; i++)
        {
            for(int j = 0 ; j < matrix[0].size() ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(int i = 0 ; i < cols.size(); i++)
        {
            int num = cols[i];
            setColZero(matrix, num);
        }
        for(int i = 0 ; i < rows.size(); i++)
        {
            int num = rows[i];
            setRowZero(matrix, num);
        }
    }
};