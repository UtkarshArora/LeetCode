class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        #hashmap store indices -> 2 loops
        #hashmap store indcies -> 1 loop
        start, end = 0, len(numbers)-1
        while start < end:
            sumNum = numbers[start] + numbers[end]
            if sumNum == target:
                return [start+1, end+1]
            elif sumNum > target:
                end-=1
            else:
                start+=1
        return []
            