class Solution:

    # def compareAnagrams(self, str1 : str, str2 : str):

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        ans = []
        stringHashes = defaultdict(list)
        for string in strs:
            arr = [0]*26
            for ch in string:
                index = ord(ch) - ord('a')
                arr[index]+=1
            
            key = tuple(arr)
            stringHashes[key].append(string)
        
        for k, v in stringHashes.items():
            ans.append(v)
        
        return ans

        

        
        