class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int k1;
    KthLargest(int k, vector<int>& nums) {
        k1 = k;
        for (int num : nums) {
            this->add(num);
        }
    }

    int add(int val) {

        if (pq.size() < k1) {
            pq.push(val);
        } else {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */