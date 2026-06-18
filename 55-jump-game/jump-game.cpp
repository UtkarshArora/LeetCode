class Solution {
public:


    // bool canJump(vector<int>& nums, int index)
    // {
    //     int n = nums.size();
    //     if(index >=n-1){
    //         return true;
    //     }
    //     for(int i = index ; i < n ; i++)
    //     {
    //         int val = nums[i];
    //         if(val == 0){
    //             return false;
    //         }
    //         for(int count = 1 ; count <=val ; count++)
    //         {
    //             if(canJump(nums, index+count)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool canJump(vector<int>& nums) {
        
        //return canJump(nums, 0);
        int n = nums.size();
        int maxsoFar = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(maxsoFar < i)
            {
                return false;
            }
            maxsoFar = max(maxsoFar, i + nums[i]); 
        }
        return true;
    }
};