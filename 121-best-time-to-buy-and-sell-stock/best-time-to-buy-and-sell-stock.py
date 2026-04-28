class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minVal = prices[0]
        maxProfit = 0
        for price in prices:
            if price < minVal:
                minVal = price
            else:
                profit = price - minVal
                maxProfit = max(profit, maxProfit)
        return maxProfit
        