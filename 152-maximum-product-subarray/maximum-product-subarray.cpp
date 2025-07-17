class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxPro = INT_MIN;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            int pro = nums[i];
            maxPro = max(pro, maxPro);
            for(int j = i+1 ; j < nums.size() ; j++)
            {
                pro = pro * nums[j];
                maxPro = max(pro, maxPro);
            }
        }
        return maxPro;
    }
};