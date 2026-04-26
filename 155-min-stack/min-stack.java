class MinStack {


    Stack<Integer>st;
    Stack<Integer>minStack;

    public MinStack() {
        st = new Stack<>();
        minStack = new Stack<>();
    }
    
    public void push(int val) {
        if(st.isEmpty())
        {
            minStack.push(val);
        }
        else
        {
            int min_val = Math.min(minStack.peek(), val);
            minStack.push(min_val);
        }
        st.push(val);
    }
    
    public void pop() {
        st.pop();
        minStack.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return minStack.peek();
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