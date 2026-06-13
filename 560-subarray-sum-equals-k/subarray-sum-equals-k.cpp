class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int total = 0;
        // creating all possible combinations of subarrays is O(n^2)
        vector<int>prefix(n,0);
        prefix[0] = nums[0];

        for(int i = 1 ; i < n; i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++)
        {
            if(prefix[i] == k){
                total++;
            }
            if(mp.find(prefix[i]-k)!=mp.end())
            {
                total+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return total;
    }
};