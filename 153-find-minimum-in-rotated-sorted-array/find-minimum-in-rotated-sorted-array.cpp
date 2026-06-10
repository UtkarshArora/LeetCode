class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int end = nums.size()-1;
        int start = 0;
        while(start < end)
        {
            int mid = start + (end-start)/2;
            
            if(nums[end] < nums[mid])
                start = mid+1;
            else
                end = mid;
        }
        return nums[start];
    }
};