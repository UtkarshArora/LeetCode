class Solution {
public:

    int numWays(vector<int>& nums, int sum, int target, int index, vector<vector<int>>&dp, int maxSum)
    {
        if(index == nums.size()){
            if(sum - maxSum == target)
            {
                return 1;
            }
            return 0;
        }
        if(dp[index][sum]!=-1)
        {
            return dp[index][sum];
        }
        int ans1 = numWays(nums, sum + nums[index], target, index+1, dp, maxSum);
        int ans2 = numWays(nums, sum - nums[index], target, index+1, dp, maxSum);
        dp[index][sum] = ans1 + ans2;
        return ans1+ans2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int maxSum = 0;
        for(int num : nums){
            maxSum+=num;
        }
        vector<vector<int>>dp(n, vector<int>(2*maxSum+2, -1));
        int ans = numWays(nums, maxSum, target, 0, dp, maxSum);
        return ans;
    }
};