class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);

        int mult = 1;
        for(int i = 1 ; i < n ; i++)
        {
            mult = mult * nums[i-1];
            prefix[i] = mult;
        }
        mult = 1;
        for(int i = n-2; i >= 0 ; i--)
        {
            mult = mult * nums[i+1];
            suffix[i] = mult; 
        }
        vector<int>ans(n,1);

        for(int i = 0 ; i < n ; i++)
        {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};