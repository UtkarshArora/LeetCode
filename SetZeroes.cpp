class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        boolean col0 = false;
        boolean row0 = false;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(matrix[i][0] == 0)
            {
                col0 = true;
            }
        }
        for(int j = 0 ; j < m ; j++)
        {
            if(matrix[0][j] == 0)
                row0 = true;
        }
        // the first 2 loops can be filled in this loop below as well, main idea of this question was to solve row and col as indices to store zeroes, also matrix[0][0] == 0, or not is a big issue
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 1; j < m ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 1 ; j < m ; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if(col0 == true)
        {
            for(int i = 0; i < n ; i++)
            {
                matrix[i][0] = 0;
            }
        }
        if(row0 == true)
        {
            for(int j = 0; j < m ; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
}
