class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>>pq; 
    int numElements;

    KthLargest(int k, vector<int>& nums) {

        numElements = k;
        for(int num : nums){

            if(pq.size() < k)
                pq.push(num);

            else if(pq.top() < num)
            {
                pq.pop();
                pq.push(num);
            }
        }
    }
    
    int add(int val) {
        
        if(pq.size() < numElements)
        {
            pq.push(val);
        }
        else if(val > pq.top())
            {
                pq.pop();
                pq.push(val);
            }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */