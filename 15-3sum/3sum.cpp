class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int target = -nums[i];
            int start = i + 1, end = n - 1;
            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum == target) {
                    vector<int> v1 = {nums[i], nums[start], nums[end]};
                    ans.push_back(v1);
                    start++;
                    end--;
                    while (start < n && nums[start - 1] == nums[start]) {
                        start++;
                    }
                    while (end >=0 && nums[end+1] == nums[end]) {
                        end--;
                    }
                    // cout<<"start: "<<start<<endl;
                    // cout<<"end: "<<end<<endl;
                }
                if (sum > target){
                    end--;
                }
                else if (sum < target){
                    start++;
                }
            }
        }
        return ans;
    }
};