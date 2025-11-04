class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        priority_queue<pair<int,int>>pq;
        int count = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(i == 0)
            {
                count = 1;
            }
            else if(nums[i]!=nums[i-1])
            {
                pair<int,int>p1 = {count, nums[i-1]};
                pq.push(p1);
                count = 1;
            }
            else
            {
                count++;
            }
        }
        pq.push({count,nums[n-1]});
        vector<int>ans;
        while(k)
        {
            pair<int,int>p = pq.top();
            int num = p.second;
            ans.push_back(num);
            pq.pop();
            k--;
        }
        return ans;
    }
};