class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>map1;
        vector<int>ans;
        for(int i = 0 ; i < nums.size(); i++)
        {
            int num = nums[i];
            int diff = target - num;
            if(map1.count(diff))
            {
                int index = map1[diff];
                ans.push_back(index);
                ans.push_back(i);
                break;
            }
            map1[num] = i;
        }
        return ans;
    }
};