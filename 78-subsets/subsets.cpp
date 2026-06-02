class Solution {
public:

    void subset(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>&res)
    {
        if(index == nums.size())
        {
            res.push_back(path);
            return;
        }
        path.push_back(nums[index]);
        subset(nums, index+1, path, res);
        path.pop_back();
        subset(nums, index+1, path, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>res;
        vector<int>path;
        subset(nums, 0, path, res);
        return res;
    }
};