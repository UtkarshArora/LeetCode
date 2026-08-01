class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        #sort the individual strings, check if something like that exists in the dictionay
        wordDict = defaultdict(list)
        for s1 in strs:
            sorted_text = "".join(sorted(s1))
            wordDict[sorted_text].append(s1)
        
        return list(wordDict.values())

            
            