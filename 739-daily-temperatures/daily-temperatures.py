class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        st = []
        ans = []
        n = len(temperatures)
        for i in range(n-1, -1, -1):
            while(len(st)!=0 and temperatures[st[-1]] <= temperatures[i]):
                st.pop()
            if(len(st) == 0):
                ans.append(0)
            else:
                index = st[-1]
                ans.append(index - i)
            st.append(i)
        ans.reverse()
        return ans
                
