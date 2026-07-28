class Solution {
public:

    int numWays(vector<int>& nums, int sum, int target, int index, vector<unordered_map<int,int>>&dp)
    {
        if(index == nums.size()){
            if(sum == target)
            {
                return 1;
            }
            return 0;
        }
        if(dp[index].find(sum)!=dp[index].end())
        {
            return dp[index][sum];
        }
        int ans1 = numWays(nums, sum + nums[index], target, index+1, dp);
        int ans2 = numWays(nums, sum - nums[index], target, index+1, dp);
        dp[index][sum] = ans1 + ans2;
        return ans1+ans2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<unordered_map<int,int>>dp(n);
        int ans = numWays(nums, 0, target, 0, dp);
        return ans;
    }
};