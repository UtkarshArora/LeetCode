class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        vector<int>op(n,0);

        int pre = 1;
        for(int i = 0 ; i < n ; i++)
        {
            pre = pre * nums[i];
            prefix[i] = pre;
        }
        int suff = 1;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            suff = suff * nums[i];
            suffix[i] = suff;
        }

        for(int i = 0 ; i < n ; i++)
        {
            int mult = 1;
            if(i > 0)
            {
                mult = mult * prefix[i-1];
            }
            if(i < n-1)
            {
                mult = mult * suffix[i+1];
            }
            op[i] = mult;
        }
        return op;
    }
};