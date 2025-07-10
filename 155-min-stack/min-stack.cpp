class MinStack {
public:

    list<int>l;
    list<int>minVals;

    MinStack() {
    }
    
    void push(int val) {

        l.push_front(val);
        bool inserted = false;
        if(minVals.empty() || val <= minVals.front())
        {
            minVals.push_front(val);
        }
        else
        {
            for(auto it = minVals.begin() ; it!=minVals.end() ;)
            {
                if(val >= *it)
                    it++;
                else{
                    minVals.insert(it, val);
                    inserted = true;
                    break;
                }
            }
            if(!inserted)
                minVals.push_back(val);       
        }
    }
    
    void pop() {

        int val = l.front();
        l.pop_front();
        for(auto it = minVals.begin() ; it!=minVals.end() ; it++)
        {
            if(*it == val){
                minVals.erase(it);
                break;
            }
        }
    }
    
    int top() {
        return l.front();
    }
    
    int getMin() {
        return minVals.front();
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