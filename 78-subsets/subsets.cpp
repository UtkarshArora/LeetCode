class Solution {
public:

    void subset(vector<int>& nums, int index, vector<int>&curr,vector<vector<int>>&res)
    {
        if(index == nums.size())
        {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        cout<<"index:"<<index<<endl;
        
        subset(nums, index+1, curr, res);
        curr.pop_back();
        subset(nums, index+1, curr, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>res;
        vector<int>curr;
        subset(nums, 0, curr, res);
        return res;
    }
};