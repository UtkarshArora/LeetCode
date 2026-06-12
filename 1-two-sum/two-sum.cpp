class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // approach 1: use 2 loop, n^2
        // approach 2: traverse 2 times, O(n), store in hashmap
        // approach 3: traverse once, O(n)

        unordered_map<int,int>indices;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int complement = target - nums[i];
            if(indices.find(complement)!=indices.end())
            {
                int index = indices[complement];
                return {index, i};
            }
            indices[nums[i]] = i;
        }
        return {-1,-1};
    }
};