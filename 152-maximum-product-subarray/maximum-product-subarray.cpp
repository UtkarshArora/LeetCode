class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProd = INT_MIN;
        for(int i = 0 ; i < nums.size(); i++)
        {
            int prod = nums[i];
            maxProd = max(prod, maxProd);
            for(int j = i+1; j < nums.size() ; j++)
            {   
                prod*=nums[j];
                maxProd = max(prod, maxProd);
            }
        }
        return maxProd;
    }
};