class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>map1;
        vector<int>ans;
        for(int num : nums)
        {
            map1[num]++;
        }
        for(auto p : map1)
        {
            int num1 = p.first;
            int num2 = p.second;
            pair<int,int>p1(num2, num1);
            pq.push(p1);
        }
        while(k > 0)
        {
            pair<int,int>p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            k--;
        }
        return ans;
    }
};