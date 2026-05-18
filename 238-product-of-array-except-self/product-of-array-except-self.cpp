class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // number 1 solution: double loop
        int n = nums.size();

        vector<int>ans(n, 0);
        // for(int i = 0 ; i < nums.size() ; i++)
        // {
        //     int prod = 1;
        //     for(int j = 0 ; j < nums.size() ; j++)
        //     {
        //         if(j == i)
        //             continue;
        //         prod = prod * nums[j];
        //     }
        //     ans[i] = prod;
        // }

        // number 2 solution: have prod of the numbers to the right
        vector<int>prodNums(n, 0);
        int prod = 1;
        for(int i = n - 1 ; i >=0 ; i--)
        {
            prodNums[i] = prod;
            prod*= nums[i];
        }
        prod = 1;
        for(int i = 0 ; i < n ; i++)
        {
            ans[i] = prod * prodNums[i];
            prod*= nums[i];
        }
        return ans;
    }
};