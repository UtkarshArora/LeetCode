class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # 2 loops-> O(n^2) time complexity, O(1) space
        # for every element, store the product of elements on left and right

        prefix = [1]*len(nums)
        suffix = [1]*len(nums)
        ans = [1]*len(nums)
        prod = 1
        for i in range(len(nums)):
            prefix[i] = prod
            prod*=nums[i]
        prod = 1
        for i in range(len(nums)-1, -1, -1):
            suffix[i] = prod
            prod*=nums[i]
        
        for i in range(len(nums)):
            ans[i] = suffix[i]*prefix[i]

        return ans
        
