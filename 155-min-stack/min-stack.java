class MinStack {

    TreeMap<Integer, List<Integer>>mp = new TreeMap<>();
    Stack<Integer>st = new Stack<>();
    
    public MinStack() {
        
    }
    
    public void push(int val) {
        st.push(val);
        List<Integer>list1 = mp.getOrDefault(val, new ArrayList<>());
        list1.add(val);
        mp.put(val, list1);
    }
    
    public void pop() {

        if(st.isEmpty())
            return;
        int val = st.peek();
        List<Integer> list1 = mp.get(val);
        list1.remove(list1.size()-1);
        if(list1.size()!= 0)
            mp.put(val, list1);
        else
            mp.remove(val);
        st.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return mp.firstKey();
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