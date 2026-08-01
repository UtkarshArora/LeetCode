class Solution:
    def isValid(self, s: str) -> bool:
        charSet = []
        for ch in s:
            if ch == '(' or ch == '[' or ch == '{':
                charSet.append(ch)
            else:
                if ch == ')' and (len(charSet) == 0 or charSet[-1]!='('):
                    return False
                elif ch == '}' and (len(charSet) == 0 or charSet[-1]!='{'):
                    return False
                elif ch == ']' and (len(charSet) == 0 or charSet[-1]!='['):
                    return False
                else:
                    charSet.pop()
        return len(charSet) == 0