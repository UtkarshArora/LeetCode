class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magDict = {}
        for ch in magazine:
            if ch in magDict:
                magDict[ch]+=1
            else:
                magDict[ch] = 1
        for ch in ransomNote:
            if ch not in magDict:
                return False
            elif magDict[ch] > 0:
                magDict[ch]-=1
            elif magDict[ch] == 0:
                return False
        return True
        