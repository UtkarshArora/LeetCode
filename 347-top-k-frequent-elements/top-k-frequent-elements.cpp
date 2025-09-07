struct compare{
    bool operator()(pair<int,int>&p1, pair<int,int>&p2)
    {
        return p1.first < p2.first;
    }
};

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>map1;
        for(int num : nums)
        {
            map1[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare>pq;
        for(int num : nums)
        {
            if(map1.find(num)!=map1.end())
                pq.push({map1[num], num});
            map1.erase(num);
        }
        vector<int>ans;
        while(k)
        {
            pair<int,int>p1 = pq.top();
            pq.pop();
            ans.push_back(p1.second);
            k--;
        }
        return ans;
    }
};