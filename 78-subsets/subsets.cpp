class Solution {
public:

    void sub(vector<int>& nums, int index, vector<int>v1, vector<vector<int>>&res)
    {
        if(index == nums.size()){
            res.push_back(v1);
            return;
        }
        sub(nums, index+1, v1, res);
        v1.push_back(nums[index]);
        sub(nums, index+1, v1, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>res;
        vector<int>v1;
        sub(nums, 0, v1, res);
        return res;
    }
};