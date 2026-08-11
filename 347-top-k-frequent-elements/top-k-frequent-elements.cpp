class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // O(NlogN) time, O(N) space
        // store freq in hashmap, then insert by {freq, num} in priority queue
        unordered_map<int,int>numFreq;
        for(int num : nums)
        {
            numFreq[num]++;
        }
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        for(auto p1 : numFreq)
        {
            pair<int,int>p = make_pair(p1.second, p1.first);
            pq.push(p);
            if(pq.size() > k){
                pq.pop();
            }
        }
        int count = 0;
        vector<int>res;
        while(count < k)
        {
            pair<int,int>p = pq.top();
            pq.pop();
            res.push_back(p.second);
            count++;
        }
        return res;
    }
};