class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int count = 1;
        int maxCount = count;
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                count++;
            //cout<<count<<" "<<nums[i-1]<<" "<<nums[i]<<endl;
                maxCount = max(count, maxCount);
            }
            else if(nums[i] == nums[i-1])
                continue;
            else
                count = 1;
        }
        return maxCount;
    }
};