class Solution {
public:
    long long minOperations(vector<int>& nums) {
        
        long long sum = 0;
        vector<long long>v1;
        for(int i = 0 ; i < nums.size() ; i++){
            long long num2 = (long long)(nums[i]);
            v1.push_back(num2);
        }
        int n = nums.size();

        for(int i = 1 ; i < n ; i++)
        {
            v1[i]+=sum;
            if(v1[i]>=v1[i-1])
            {
                continue;
            }
            else
            {
                long long diff = v1[i-1] - v1[i];
                sum+=diff;
                v1[i]+=diff;
            }
        }
        return sum;
    }
};