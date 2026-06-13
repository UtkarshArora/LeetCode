class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int total = 0;
        // creating all possible combinations of subarrays is O(n^2)
        for(int i = 0 ; i < n; i++)
        {
            int sum = nums[i];
            if(sum == k)
            {
                total+=1;
            }
            for(int j = i+1; j < n ; j++)
            {
                sum+=nums[j];
                if(sum == k)
                {
                    total+=1;
                }
            }
        }
        return total;
    }
};