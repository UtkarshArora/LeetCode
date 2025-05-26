// if price < minPrice, minPrice is set, else we subtract price from minPrice, check if profit is maxProfit or not, find the maxProfit
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size() ; i++)
        {
            if(prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else
            {
                int profit = prices[i] - minPrice;
                if(profit > maxProfit)
                {
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }
};
