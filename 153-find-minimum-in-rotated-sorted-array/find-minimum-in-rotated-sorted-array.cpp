class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int start = 0, end = n - 1;

        while(start < end)
        {
            if(nums[start] < nums[end])
                return nums[start];

            int mid = start + (end - start)/2;

            if (nums[start] > nums[mid])
                end = mid;
            else
                start = mid+1;
        }
        return nums[start];
    }
};