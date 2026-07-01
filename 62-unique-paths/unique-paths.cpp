class Solution {
public:

    // int unique(int m, int n, int i, int j, vector<vector<int>>&dp)
    // {
    //     if(i == m || j == n){
    //         return 0;
    //     }
    //     if(i == m-1 || j == n-1){
    //         return 1;
    //     }
    //     if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }
    //     dp[i][j] = unique(m, n, i+1, j, dp) + unique(m, n, i, j+1, dp);
    //     return dp[i][j];
    // }
    int uniquePaths(int m, int n) {

        vector<vector<int>>dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = 1;
        for(int j = 0 ; j < n-1 ; j++)
        {
            dp[m-1][j] = 1;
        }
        for(int i = 0 ; i < m-1 ; i++)
        {
            dp[i][n-1] = 1;
        }
        for(int i = m-2 ; i >=0 ; i--)
        {
            for(int j = n-2 ; j >=0 ; j--)
            {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};