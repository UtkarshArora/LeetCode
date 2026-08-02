class Solution:
    def isPalindrome(self, s: str) -> bool:
        start = 0; end = len(s)-1
        while start < end:
            while start < end and s[start].isalnum() is False:
                start+=1
            while start < end and s[end].isalnum() is False:
                end-=1
            if start < end:
                if s[start].lower() == s[end].lower():
                    start+=1
                    end-=1
                else:
                    return False
            else:
                return True
        return True