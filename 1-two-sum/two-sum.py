class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        indices = dict()
        ans = [-1,-1]
        for i in range(len(nums)):
            diff = target - nums[i]
            if(diff in indices):
                ans[0] = indices.get(diff)
                ans[1] = i
                break
            else:
                indices[nums[i]] = i
        return ans


        