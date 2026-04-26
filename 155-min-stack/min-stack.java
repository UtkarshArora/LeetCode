class MinStack {

    Stack<int[]>st;
    public MinStack() {
        st = new Stack<>();
    }
    
    public void push(int val) {
        int[] top = st.isEmpty()? new int[]{val, val} : st.peek();
        int min_val = top[1];
        if(val < min_val)
        {
            min_val = val;
        }
        st.push(new int[]{val, min_val});
    }
    
    public void pop() {
        st.pop();
        return;
    }
    
    public int top() {
        return st.peek()[0];
    }
    
    public int getMin() {
        return st.peek()[1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */