class Solution:
    def isPalindrome(self, s: str) -> bool:
        start, end = 0, len(s)-1
        while start < end:
            while start < end and s[start].isalnum() is False:
                start+=1
            while start < end and s[end].isalnum() is False:
                end-=1
            if start < end and s[start].lower()!= s[end].lower():
                return False
            start+=1
            end-=1
        return True