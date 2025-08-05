class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>suffix(n,1);
        //vector<int>ans(n, 1);
        for(int i = n-2; i >=0 ; i--)
        {
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        int mul = 1;
        for(int i = 0 ; i < n ; i++)
        {
            suffix[i] = mul * suffix[i];
            mul = mul * nums[i];
        }
        return suffix;
    }
};