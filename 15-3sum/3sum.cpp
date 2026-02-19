class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        unordered_set<string>set1;
        for(int i = 0 ; i < n-2 ; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int sum = nums[i];
            int start = i+1, end = n-1;
            while(start < end)
            {
                int sum2 = nums[start] + nums[end];
                if(sum2 + sum == 0)
                {
                    string s1 = to_string(nums[i]) + "#" + to_string(nums[start]) + "#"+ to_string(nums[end]);
                    if(!set1.count(s1)){
                        set1.insert(s1);
                        vector<int>v1 = {nums[i], nums[start], nums[end]};
                        ans.push_back(v1);
                    }
                    start++;
                    end--;
                }
                else if(sum2 + sum > 0)
                {
                    end--;
                }   
                else
                {
                    start++;
                }
            }
        }
        return ans;
    }
};