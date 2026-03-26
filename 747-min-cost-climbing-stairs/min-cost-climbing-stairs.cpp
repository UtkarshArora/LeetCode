class Solution {
public:

    int minCost(vector<int>& cost, vector<int>&dp, int index)
    {
        if(index <= 1)
            return cost[index];

        if(dp[index]!=-1)
            return dp[index];
        
        dp[index] = cost[index] + min(minCost(cost,dp, index-1), minCost(cost,dp,index-2));

        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        dp[n] = min(minCost(cost,dp,n-1), minCost(cost,dp, n-2));
        return dp[n];
    }
};