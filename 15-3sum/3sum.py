class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:

        ans = []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            start = i + 1
            end = len(nums) - 1
            while start < end :
                sum_total = nums[i] + nums[start] + nums[end]
                
                if sum_total < 0 :
                    start+=1
                elif sum_total > 0 :
                    end-=1
                elif sum_total == 0:
                    list1 = [nums[i], nums[start], nums[end]]
                    ans.append(list1)
                    start+=1
                    while start < end and nums[start] == nums[start-1]:
                        start+=1
        return ans

