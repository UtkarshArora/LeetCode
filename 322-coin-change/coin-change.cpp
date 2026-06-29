class Solution {
public:

    // returns the min coins for the given amount
    int minCoins(vector<int>& coins, int amount, vector<int>&memo)
    {
        if(amount == 0)
        {
            return 0;
        }
        if(amount < 0)
        {
            return -1;
        }
        if(memo[amount]!=-2)
        {
            return memo[amount];
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < coins.size() ; i++)
        {   
            int num = minCoins(coins, amount - coins[i], memo);
            if(num == -1)
            {
                continue;
            }
            ans = min(ans, 1 + num);
        }
        memo[amount] = ans!=INT_MAX ? ans : -1;
        return memo[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<int>memo(amount+1, -2);
        memo[0] = 0;
        int ans = minCoins(coins, amount, memo);
        return memo[amount];
    }
};