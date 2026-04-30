class Solution {
    public int maxSubArray(int[] nums) {
        
        if(nums.length == 0)
            return 0;
        
        int maxSum = nums[0];
        int curr_sum = nums[0];
        for(int i = 1 ; i < nums.length ; i++)
        {
            curr_sum = curr_sum + nums[i];
            if(nums[i] > curr_sum)
            {
                curr_sum = nums[i];
            }
            maxSum = Math.max(curr_sum, maxSum);
        }
        return maxSum;
    }
}