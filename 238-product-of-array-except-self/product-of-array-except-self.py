class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        n = len(nums)
        suffix = [1]*n
        ans = [1]*n
        prod = 1
        for i in range(n-1, -1, -1):
            suffix[i] = prod
            prod*= nums[i]
        
        prod = 1
        for i in range(n):
            ans[i] = suffix[i]*prod
            prod*=nums[i]
        
        return ans

        