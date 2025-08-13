class Solution {
public:

    int minD(string word1, string word2, int index1, int index2, vector<vector<int>>&dp)
    {
        if(index1 == word1.size())
            return (word2.size() - index2);
        if(index2 == word2.size())
            return (word1.size() - index1);
        
        if(dp[index1][index2]!=0)
            return dp[index1][index2];
        
        int ans1 = (int)(word1[index1]!=word2[index2]) + minD(word1, word2, index1+1, index2+1, dp);    
        int ans2 = 1 + minD(word1, word2, index1, index2+1, dp);

        int ans3 = 1 + minD(word1, word2, index1+1, index2, dp);

        dp[index1][index2] = min(ans1, min(ans2, ans3));

        return dp[index1][index2];
}
    int minDistance(string word1, string word2) {
        
        int s1 = word1.size();
        int s2 = word2.size();
        vector<vector<int>>dp(s1+1, vector<int>(s2+1, 0));
        return minD(word1, word2, 0,0, dp);
    }
};