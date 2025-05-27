class Solution {
public:

    void swapRows(vector<vector<int>>& matrix, int i, int j)
    {
        int numCols = matrix[i].size();
        for(int index = 0 ; index < numCols ; index++)
        {
            swap(matrix[i][index], matrix[j][index]);
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        for(int i = 0 ; i < n/2 ; i++)
        {
            int j = n - 1 - i;
            swapRows(matrix, i, j);
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < matrix[i].size() ; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

    }
};
