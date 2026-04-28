class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = 0
        end = 0
        indices = {}
        maxlen = 0
        while(end < len(s)):
            ch = s[end]
            if(ch in indices):
                start = max(start, indices[s[end]]+1)
            len1 = end - start + 1
            maxlen = max(len1, maxlen)
            indices[s[end]] = end
            end+=1
        return maxlen

        