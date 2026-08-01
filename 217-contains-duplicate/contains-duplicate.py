class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        #approach 1 : 2 loops, n^2
        #approach 2: store in set or hashmap
        numCount = set()
        for num in nums:
            if num in numCount:
                return True
            numCount.add(num)
        return False