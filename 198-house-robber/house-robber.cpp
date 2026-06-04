class Solution {
public:

    int maxRob(vector<int>&nums, int index, vector<int>&dp)
    {
        if(index == 0)
            return nums[0];
        if(index == 1)
            return max(nums[0], nums[1]);
        if(dp[index]!=-1)
            return dp[index];
        
        dp[index] = max(maxRob(nums, index-2, dp) + nums[index], maxRob(nums, index-1, dp));
        return dp[index];
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n, -1);
        if(n >= 1){
            dp[0] = nums[0];
        }
        if(n >= 2){
            dp[1] = max(nums[0], nums[1]);
        }
        for(int i = 2; i < n ; i++)
        {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};