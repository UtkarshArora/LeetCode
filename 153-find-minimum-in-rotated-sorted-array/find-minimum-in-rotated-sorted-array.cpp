class Solution {
public:
    int findMin(vector<int>& nums) {
        
        // sorted in ascending order, one drop, then sorted again
        // middle < end
        int start = 0, end = nums.size()-1;
        while(start < end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] < nums[end])
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            }
        }
        return nums[start];
    }
};