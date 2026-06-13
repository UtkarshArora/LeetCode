class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
      
        unordered_map<int,int>freq;
        vector<int>ans;
        for(int num : nums)
        {
            freq[num]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto p : freq)
        {
            pair<int,int>p1 = make_pair(p.second, p.first);
            pq.push(p1);
        }
        int count = 0;
        while(count < k)
        {
            pair<int,int>p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            count++;
        }
        return ans;
    }
};