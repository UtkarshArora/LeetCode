class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        

        int n = nums.size();
        if(n == 0)
            return 0;
        sort(nums.begin(), nums.end());

        int maxCons = 1;
        int cons = 1;
        int prev = nums[0];

        for(int i = 1 ; i < n; i++)
        {
            if(nums[i] == (prev + 1))
            {
                cons++;
                prev = nums[i];
            }
            else if(nums[i] == prev)
            {
                continue;
            }
            else{
                cons = 1;
                prev = nums[i];
            }
            maxCons = max(cons, maxCons);
        }
        return maxCons;
    }
};