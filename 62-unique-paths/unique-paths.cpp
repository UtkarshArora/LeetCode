class Solution {
public:
    // int uniqueP(int x, int y, int m, int n, vector<vector<int>>paths)
    // {
    //     if(x >= m || y >=n)
    //         return 0;
    //     if(x == m-1 && y == n-1)
    //         return 1;
    // }
    int uniquePaths(int m, int n) {

        vector<vector<int>>paths(m, vector<int>(n,0));
        paths[0][0] = 1;
        for(int i = 0 ; i < m ; i++)
        {
            paths[i][0] = 1;
        }
        for(int j = 0; j < n ; j++)
        {
            paths[0][j] = 1;
        }
        for(int i = 1 ; i < m ; i++)
        {
            for(int j = 1 ; j < n ; j++)
            {
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[m-1][n-1];
    }
};