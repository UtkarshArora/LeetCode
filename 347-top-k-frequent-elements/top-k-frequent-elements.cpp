class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        // store number its frequency in hashmap -> O(n)
        unordered_map<int,int>map1;

        for(int num : nums)
        {
            map1[num]++;        
        }

        // store pair of freq and number in the max priority queue -> O(nlogn)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto p1 : map1)
        {
            pair<int,int>p = make_pair(p1.second, p1.first);
            pq.push(p);
            if(pq.size() > k)
                pq.pop();
        }

        // retrieve top k elements from the heap.   -> O(klogn)
        // int count = 0;
        vector<int>finalAns;                
        while(!pq.empty())
        {
            auto p1 = pq.top(); pq.pop();
            finalAns.push_back(p1.second);
        }
        return finalAns;
    }
};