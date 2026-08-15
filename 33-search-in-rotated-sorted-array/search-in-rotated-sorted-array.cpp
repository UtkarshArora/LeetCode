class Solution {
public:

    int findMinimum(vector<int>& nums)
    {
        int start = 0, end = nums.size()-1;
        while(start < end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] < nums[end]){
                end = mid;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }

    int binarySearch(vector<int>&nums, int start, int end, int target)
    {
        if(start < 0 || end < 0 || start >= nums.size() || end >=nums.size()){
            return -1;
        }
        while(start < end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return nums[start] == target ? start : -1;
    }
    int search(vector<int>& nums, int target) {
        
        // time complexity -> O(n), space-> O(1)
        // get inflection point or the minimum value from nums
        // apply binary search in these ranges [start, index-1] [index, end]
        //[7, 10, 0, 1, 2, 5, 6]
        int index = findMinimum(nums);
        auto it1 = lower_bound(nums.begin(), nums.begin() + index, target);

        if(it1!= nums.begin()+index && *it1 == target){
            return (it1 - nums.begin());
        }
        auto it2 = lower_bound(nums.begin() + index, nums.end(), target);
        if(it2 == nums.end()){
            return -1;
        }
        return (*it2 == target)? (it2 - nums.begin()) : -1;
    }
};