class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        ans = [-1,-1]
        start = 0 
        end = len(numbers) - 1
        while(start < end):
            sum1 = numbers[start] + numbers[end]
            if sum1 == target:
                ans = [start+1, end+1]
                return ans
            elif sum1 < target:
                start+=1
            else:
                end-=1
        return ans

        