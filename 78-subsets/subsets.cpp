class Solution {
public:
    vector<vector<int>>ans;
    void subSet(vector<int>v1, vector<int>& nums, int index)
    {
        if(index == nums.size())
        {
            ans.push_back(v1);
            return;
        }
        subSet(v1, nums, index+1);
        v1.push_back(nums[index]);
        subSet(v1, nums, index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v1 = {};
        subSet(v1, nums, 0);
        return ans;
    }
};