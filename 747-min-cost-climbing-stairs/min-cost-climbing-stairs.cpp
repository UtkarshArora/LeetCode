class Solution {
public:

    int minCost(vector<int>& cost, vector<int>&dp, int index)
    {
        int n = cost.size();
        if(index < 0)
            return 0;
        if(index <= 1)
            return cost[index];
        if(dp[index]!=-1)
            return dp[index];
        int currentCost = (index == n)? 0 : cost[index];
        dp[index] = currentCost + min(minCost(cost, dp, index-1), minCost(cost, dp, index-2));
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int>dp(n+1,-1);
        // vector<int>dp(n,0);
        // if(n == 0)
        //     return 0;
        // if(n == 1)
        //     return cost[0];
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        // for(int i = 2 ; i < n ; i++)
        // {
        //     dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        // }
        // return min(dp[n-1], dp[n-2]);
        return minCost(cost, dp, n);
    }
};