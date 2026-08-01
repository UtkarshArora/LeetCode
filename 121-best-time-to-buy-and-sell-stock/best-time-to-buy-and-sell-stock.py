class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = float('inf')
        res = 0
        for x in prices:
            if x < minPrice:
                minPrice = x
            else:
                profit = x - minPrice
                res = max(res, profit)
        return res