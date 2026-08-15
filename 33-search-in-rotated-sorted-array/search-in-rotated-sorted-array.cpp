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
        cout<<index<<endl;
        // if(nums[index] == target){
        //     return index;
        // }
        int ans1 = binarySearch(nums, 0, index-1, target);
        int ans2 = binarySearch(nums, index, nums.size()-1, target);
        return ans1!=-1? ans1 : ans2;
    }
};