class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int res = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < minPrice)
                minPrice = prices[i];
            int profit = prices[i] - minPrice;
            res = max(profit, res);
        }
        return res;
    }
};