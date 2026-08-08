class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 3 indices, x, y and z, but how do we keep track of these indices
        // n^3 solution is 3 loops

        // n^2 -> fix one index, traverse the remaining part using 2 pointers, by sorting the array

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        for(int i = 0 ; i < n ; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int num = nums[i];
            int target = -nums[i];
            int start = i+1, end = n-1;
            while(start < end)
            {
                int sum = nums[start] + nums[end];
                if(sum == target)
                {
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    while(start < end && nums[start] == nums[start-1]){
                        start++;
                    }
                    end--;
                    while(start < end && nums[end] == nums[end+1]){
                        end--;
                    }
                }
                else if(sum > target){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return res;
    }
};