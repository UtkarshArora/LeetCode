class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // at every index, make a choice, either start a new subsequence from here or continue the subsequence

        // some observations: take minimum value at the leftmost index, and then start from that, but leftmost and what is minimum cannot be defined because we did not see all the elements on the right

        int n = nums.size();
        int maxVal = 1;
        vector<int>dp(n, 1);
        for(int i = n-2 ; i >=0 ; i--)
        {
            // find immediately next larger number
            int nextMax = INT_MIN;
            for(int j = i+1 ; j < n ; j++)
            {
                if(nums[j] <= nums[i])
                {
                    continue;
                }
                else
                {
                    int num = nums[j] - nums[i];
                    nextMax = max(nextMax, dp[j]);
                }
            }
            if(nextMax!= INT_MIN)
            {
                dp[i] = dp[i] + nextMax;
            }
            maxVal = max(dp[i], maxVal);
        }
        return maxVal;
    }
};