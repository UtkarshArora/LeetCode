class Solution {
public:

    // int minCost(vector<int>& cost, vector<int>&dp, int index)
    // {
    //     if(index <= 1)
    //         return cost[index];

    //     if(dp[index]!=-1)
    //         return dp[index];
        
    //     dp[index] = cost[index] + min(minCost(cost,dp, index-1), minCost(cost,dp,index-2));

    //     return dp[index];
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n, -1);
        dp[0] = cost[0]; 
        dp[1] = cost[1];
        for(int i = 2 ; i < n ; i++)
        {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};