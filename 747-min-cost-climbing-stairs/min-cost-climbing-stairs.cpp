class Solution {
public:

    int minCost(vector<int>& cost, int index)
    {
        if(index < 0)
            return 0;
        if(index <= 1)
            return cost[index];

        return cost[index] + min(minCost(cost, index-1), minCost(cost, index-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int>dp(n,0);
        if(n == 0)
            return 0;
        if(n == 1)
            return cost[0];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2 ; i < n ; i++)
        {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};