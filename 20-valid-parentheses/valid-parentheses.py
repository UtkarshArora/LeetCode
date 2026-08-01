class Solution:
    def isValid(self, s: str) -> bool:
        charSet = []
        mappings = {')' : '(' , ']':'[' , '}' : '{'}
        for ch in s:
            if ch in mappings:
                topElement = charSet.pop() if charSet else '#'
                if mappings[ch]!= topElement:
                    return False
            else:
                charSet.append(ch)
        return len(charSet) == 0    
        

                