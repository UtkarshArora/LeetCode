class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        wordMap = defaultdict(list)
        for word in strs:
            sorted_text = "".join(sorted(word))
            wordMap[sorted_text].append(word)
        
        return list(wordMap.values())
