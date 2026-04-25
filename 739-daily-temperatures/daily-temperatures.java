class Solution {
    public int[] dailyTemperatures(int[] temperatures) {

        Stack<Pair<Integer, Integer>>st = new Stack<>();
        int n = temperatures.length;
        int[] ans = new int[n];
        int end = n-2;
        st.push(new Pair<Integer, Integer>(temperatures[n-1], n-1));
        while(end >= 0)
        {
            while(!st.isEmpty() && temperatures[end] >= st.peek().getKey())
            {
                st.pop();
            }
            ans[end] = (st.isEmpty())? 0 : st.peek().getValue() - end;
            st.push(new Pair(temperatures[end], end));
            end--;
        }
        return ans;   
    }
}