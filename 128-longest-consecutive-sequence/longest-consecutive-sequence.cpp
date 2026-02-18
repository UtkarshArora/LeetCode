class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int res = 1;
        int count = 1;
        int prev = nums[0];
        int n = nums.size();
        for(int i = 1 ; i < n ; i++)
        {
            if(nums[i] == (prev+1))
            {
                count++;
                prev = nums[i];
            }
            else if(nums[i] == prev)
                continue;
            else{
                res = max(res, count);
                count=1;
                prev = nums[i];
            }
        }
        return max(count,res);
    }
};