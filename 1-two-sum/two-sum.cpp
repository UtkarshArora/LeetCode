class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>map1;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(map1.find(target-nums[i])!=map1.end())
            {
                return {i, map1[target-nums[i]]};
            }
            map1[nums[i]] = i; 
        }
        return {0,0};
    }
};