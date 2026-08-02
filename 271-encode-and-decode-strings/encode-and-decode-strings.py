class Codec:
    def encode(self, strs: List[str]) -> str:
    
        encoded = ""
        for word in strs:
            encoded+=str(len(word)) + "@" + word
        return encoded
        

    def decode(self, s: str) -> List[str]:
        
        res = []
        i = 0
        while i < len(s):
            # find delimiter
            # the string before that is length of string
            # traverse length of string and add that to the answer
            index = s.find('@', i)
            #print(index)
            length = int(s[i:index])
            word = s[index+1 : index+1+length]
            #print(word)
            res.append(word)
            i = index+1+length
        return res


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))