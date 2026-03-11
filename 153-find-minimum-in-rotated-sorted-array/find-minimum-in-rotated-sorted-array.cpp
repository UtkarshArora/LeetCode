class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int mid;
        while(start < end)
        {
            mid = start + (end-start)/2;
            if(nums[mid] >= nums[start])
            {
                if(nums[mid] < nums[end])
                {
                    end = mid;
                }
                else
                {
                    start = mid+1;
                }
            }
            else if(nums[mid] < nums[start])
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