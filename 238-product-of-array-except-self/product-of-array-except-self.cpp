class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int n = nums.size();
        vector<int>suffix(n, 1);
        for(int i = n-1; i >=0 ; i--)
        {
            suffix[i] = prod;
            prod*=nums[i];
        }
        prod = 1;
        vector<int>output(n,1);
        for(int i = 0 ; i < n ; i++)
        {
            output[i] = prod * suffix[i];
            prod*= nums[i];
        }
        return output;
    }
};