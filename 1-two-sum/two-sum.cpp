class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int>ans;
        unordered_map<int,int>map1;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int diff = target - nums[i];
            if(map1.find(diff)!= map1.end())
            {
                return {i, map1[diff]};
            }
            map1[nums[i]]=i;
        }
        return {0,0};
    }
};