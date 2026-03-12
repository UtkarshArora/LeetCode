class MinStack {
public:
        list<int>l1;
        unordered_set<int>set1;
        list<int>l2;
        int minVal;
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int val) {
        l1.push_front(val);
        set1.insert(val);
        if(l2.empty() || val <= l2.front())
            l2.push_front(val);
        else
            l2.push_back(val);
    }
    
    void pop() {
        int val = l1.front();
        l1.pop_front();
        set1.erase(val);
        auto it = find(l2.begin(), l2.end(), val);
        l2.erase(it);
    }
    
    int top() {
        return l1.front();
    }
    
    int getMin() {
        return l2.front();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */