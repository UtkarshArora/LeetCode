class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>countFreq;
        vector<int>ans;

        for(int num : nums)
        {
            countFreq[num]++;
        }
        for(const auto& p : countFreq)
        {
            pair<int,int>p1 = make_pair(p.second, p.first);
            pq.push(p1);
        }
        int count = 0;
        while(count < k)
        {
            pair<int,int>p1 = pq.top();
            pq.pop();
            count++;
            ans.push_back(p1.second);
        }
        return ans;
    }
};