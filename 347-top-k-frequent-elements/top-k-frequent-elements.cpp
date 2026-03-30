class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>map1;
        for(int num : nums)
        {
            map1[num]++;
        }
        for(auto &it : map1)
        {
            pair<int,int>p = make_pair(it.second, it.first);
            pq.push(p);
        }
        int count = 0;
        vector<int>ans;
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