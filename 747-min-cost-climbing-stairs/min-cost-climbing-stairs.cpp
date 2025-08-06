class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        
        int ans = 0;
        int n = cost.size();
        //return minCostClimbing(cost, ans);
        for(int i = 2 ; i < cost.size() ; i++)
        {
            cost[i] = cost[i] + min(cost[i-1], cost[i-2]);
        }
        return min(cost[n-1], cost[n-2]);
    }
};