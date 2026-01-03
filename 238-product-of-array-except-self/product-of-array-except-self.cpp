class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>suffix(n,1);
        vector<int>op(n,0);

        int suff = 1;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            suff = suff * nums[i];
            suffix[i] = suff;
        }
        int mult = 1;
        for(int i = 0 ; i < n ; i++)
        {
            op[i] = mult;
            if(i+1 < n)
            {
                op[i] = op[i] * suffix[i+1];
            }
            mult = mult * nums[i];
        }
        return op;
    }
};