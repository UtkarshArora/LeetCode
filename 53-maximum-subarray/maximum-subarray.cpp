class Solution {
public:

    int maxSub(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return INT_MIN;
        
        if(start == end)
            return nums[start];
        
        int mid = (end + start)/2;
        int leftSum = 0, rightSum = 0;
        for(int i = mid-1, currSum = 0 ; i>=start; i--)
        {
            currSum+=nums[i];
            leftSum = max(currSum, leftSum);
        }
        for(int i = mid+1, currSum = 0 ; i <= end ; i++)
        {
            currSum+=nums[i];
            rightSum = max(currSum, rightSum);
        }
        int left = maxSub(nums, start, mid-1);
        int right = maxSub(nums, mid+1, end);
        return max(leftSum + rightSum + nums[mid], max(left, right));
    }
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0, right = n - 1;
        return maxSub(nums, left, right);
    }
};