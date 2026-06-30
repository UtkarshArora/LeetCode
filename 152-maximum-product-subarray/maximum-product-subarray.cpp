class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // n^2 solution
        int maxProd = INT_MIN;
        int prod = 1;
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++)
        {
            prod = prod * nums[i];
            maxProd = max(prod, maxProd);
            if(prod == 0)
            {
                prod = 1;
            }
        }
        prod = 1;
        for(int i = n - 1 ; i>=0 ; i--)
        {
            prod = prod* nums[i];
            maxProd = max(prod, maxProd);
            if(prod == 0)
            {
                prod = 1;
            }
        }
        return maxProd;
    }
};