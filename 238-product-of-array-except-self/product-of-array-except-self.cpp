class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>op(n, 0);
        // approach 1 : for each index, find prod of elem before i, find prod of elem after i, and store -> O(n^2) approach

        // approach 2 : to optimize this, store the elements in an array, then just compute -> use prefix and suffix

        // approach 3: no need to store prefix, compute prefix on the go, just store suffix, that will be our output array as well

        int prod = 1;
        for(int i = n-1; i >=0 ; i--)
        {
            op[i] = prod;
            prod*=nums[i];
        }
        prod = 1;
        for(int i = 0 ; i < n; i++)
        {
            op[i] = op[i]*prod;
            prod*=nums[i];
        }
        return op;
    }
};