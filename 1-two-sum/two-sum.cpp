class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>map1;
        vector<int>ans;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int num1 = target - nums[i];
            if(map1.find(num1)!=map1.end())
            {
                ans.push_back(i);
                ans.push_back(map1[num1]);
                break;
            }
            map1[nums[i]] = i;
        }
        return ans;
    }
};