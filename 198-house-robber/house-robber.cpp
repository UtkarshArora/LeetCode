class Solution {
public:

    // int sum(vector<int>& nums, int index, vector<bool>included)
    // {
    //     if(index == nums.size())
    //         return 0;
        
    //     int sum1 = 0, sum2 = 0;
    //     if(index > 0 && !included[index-1] || index == 0){
    //         included[index] = true;
    //         sum1 = nums[index] + sum(nums, index+1, included);
    //     }
    //     included[index] = false;
    //     sum2 = sum(nums, index+1, included);
    //     return max(sum1, sum2);
    // }
    // int rob(vector<int>& nums) {

    //     int n = nums.size();
    //     vector<bool>included(n, false);
    //     return sum(nums, 0, included);
    // }

    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int>maxtillNow(n, 0);
        maxtillNow[0] = nums[0];
        if(n == 1)
            return nums[0];
        maxtillNow[1] = max(nums[0], nums[1]);

        for(int i = 2 ; i < n ; i++)
        {
            maxtillNow[i] = max(maxtillNow[i-1], maxtillNow[i-2] + nums[i]);
        }
        return maxtillNow[n-1];
    }
    /*
        [1,2,3,1] -> [1] -> [1,3] -> [1,3]-> 4  , [] -> [2] -> [2,1], []
    */




};