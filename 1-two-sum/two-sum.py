class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #approach 1: 2 loops, O(1) space
        #approach 2: hashmap
        indices = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in indices:
                return [indices[complement], i]
            indices[num] = i
        return []