class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        // store number its frequency in hashmap
        unordered_map<int,int>map1;

        for(int num : nums)
        {
            map1[num]++;
        }

        // store pair of freq and number in the max priority queue
        priority_queue<pair<int,int>>pq;
        for(auto p1 : map1)
        {
            pair<int,int>p = make_pair(p1.second, p1.first);
            pq.push(p);
        }

        // retrieve top k elements from the heap
        int count = 0;
        vector<int>finalAns;
        while(count < k)
        {
            auto p1 = pq.top(); pq.pop();
            finalAns.push_back(p1.second);
            count++;
        }
        return finalAns;
    }
};