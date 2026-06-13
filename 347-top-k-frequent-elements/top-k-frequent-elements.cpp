class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
      
        unordered_map<int,int>freq;
        vector<int>ans;
        for(int num : nums)
        {
            freq[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto p : freq)
        {
            pair<int,int>p1 = make_pair(p.second, p.first);
            if(pq.size() < k)
            {
                pq.push(p1);
            }
            else if(pq.top().first < p1.first)
            {
                pq.pop();
                pq.push(p1);
            }
        }
        int count = 0;
        while(!pq.empty())
        {
            pair<int,int>p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};