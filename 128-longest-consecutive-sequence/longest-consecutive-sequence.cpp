class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, maxCount = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(i == 0){
                count++;
                maxCount = max(count, maxCount);
            }
            else{
                int diff = nums[i] - nums[i-1];
                if(diff == 1)
                {
                    count++;
                    maxCount = max(count, maxCount);
                }
                else if(diff!= 0)
                    count = 1;
            }
        }
        return maxCount;
    }
};