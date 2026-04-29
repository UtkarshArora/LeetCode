class MinStack:

    st = []
    minSt = []
    def __init__(self):
        self.st = []
        self.minSt = []
        
    def push(self, val: int) -> None:
        if len(self.minSt) == 0 or val < self.minSt[-1]:
            self.minSt.append(val)
        else:
            self.minSt.append(self.minSt[-1])
        self.st.append(val)
        
    def pop(self) -> None:
        self.st.pop()
        self.minSt.pop()

    def top(self) -> int:
        return self.st[-1]

    def getMin(self) -> int:
        return self.minSt[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()