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
        return maxRob(nums, n-1, dp);
    }
};