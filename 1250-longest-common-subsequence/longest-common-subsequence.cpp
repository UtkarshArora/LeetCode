class Solution {
public:

    // int longestCommon(string text1, string text2, int index1, int index2, vector<vector<int>>&dp)
    // {
    //     if(index1 == text1.size() || index2 == text2.size())
    //     {
    //         return 0;
    //     }
    //     if(dp[index1][index2]!=-1)
    //     {
    //         return dp[index1][index2];
    //     }
    //     if(text1[index1] == text2[index2])
    //     {
    //         dp[index1][index2] = 1 + longestCommon(text1, text2, index1+1, index2+1, dp);
    //         return dp[index1][index2];
    //     }
    //     int ans1 = longestCommon(text1, text2, index1+1, index2, dp);
    //     int ans2 = longestCommon(text1, text2, index1, index2+1, dp);
    //     dp[index1][index2] = max(ans1, ans2);
    //     return dp[index1][index2];
    // }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>>dp(n1, vector<int>(n2,0));
        for(int i = 0 ; i < n1 ; i++)
        {   
            if(text1[i] == text2[0]){
                dp[i][0] = 1;
            }
            else if(i >=1){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int j = 0; j < n2 ; j++)
        {
            if(text1[0] == text2[j]){
                dp[0][j] = 1;
            }
            else if(j >= 1){
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i = 1 ; i < n1 ; i++)
        {
            for(int j = 1 ; j < n2 ; j++)
            {
                if(text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n1-1][n2-1];
        // return longestCommon(text1, text2, 0, 0, dp);
    }
};