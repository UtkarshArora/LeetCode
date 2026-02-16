class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>countFreq;
        vector<int>ans;

        for(int num : nums)
        {
            countFreq[num]++;           // O(n) time complexity
        }
        for(const auto& p : countFreq)
        {
            pair<int,int>p1 = make_pair(p.second, p.first); 
            pq.push(p1);               // O(nlogn) time complexity
            if(pq.size() > k)
            {
                pq.pop();
            }
        }        
        while(!pq.empty())                // O(nlogn) time complexity
        {
            pair<int,int>p1 = pq.top();
            pq.pop();                     
            ans.push_back(p1.second);
        }
        return ans;
    }
};