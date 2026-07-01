class Solution {
public:

    int unique(int m, int n, int i, int j, vector<vector<int>>&dp)
    {
        if(i == m || j == n){
            return 0;
        }
        if(i == m-1 || j == n-1){
            return 1;
        }
        //cout<<"i:"<<i<<", j:"<<j<<endl;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        dp[i][j] = unique(m, n, i+1, j, dp) + unique(m, n, i, j+1, dp);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>>dp(m, vector<int>(n, -1));
        return unique(m, n, 0, 0, dp);
    }
};