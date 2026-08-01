class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        #c++ approach -> counter of 26 chars
        #python approach -> create 2 counters
        sCount = Counter(s)
        tCount = Counter(t)
        return sCount == tCount