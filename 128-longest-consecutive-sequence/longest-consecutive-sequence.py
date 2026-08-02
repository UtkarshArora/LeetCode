class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        if len(nums) == 0:
            return 0
        i = 1
        cons = 1
        maxCons = 1
        while i < len(nums):
            if nums[i] == nums[i-1]+1:
                print(nums[i])
                cons+=1
                print(cons)
            elif nums[i] == nums[i-1]:
                i+=1
                continue
            elif nums[i]!= nums[i-1]+1:
                cons = 1
            maxCons = max(cons, maxCons)
            i+=1
        return maxCons
            
