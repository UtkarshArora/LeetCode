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
        
        int n = nums.size();
        vector<bool>isPossible(n, false);
        isPossible[n-1] = true;
        for(int i = n-2 ; i >=0 ; i--)
        {
            int val = nums[i];
            if(val > 0)
            {
                for(int j = i + 1 ; j <= (i+val) && j < n ; j++)
                {
                    if(isPossible[j])
                    {
                        isPossible[i] = true;
                        break;
                    }
                }
            }
        }
        return isPossible[0];
    }
};