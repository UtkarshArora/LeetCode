class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int>suffix(n,0);
        int mult = 1;
        suffix[n-1] = 1;
        for(int i = n-2 ; i >= 0 ; i--)
        {
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        for(int i = 0 ; i < n ; i++)
        {
            suffix[i] = suffix[i] * mult;
            mult = mult * nums[i];
        }
        return suffix;
    }
};