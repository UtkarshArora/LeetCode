// push zeroes to front, if nums[curr] == 2, we don't do curr++, because we are not sure if we replaced it with 0, or what we are ensuring is that ki 0 should be before the curr pointer, 
// that's why we don't replace
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int curr = 0, nZ = 0, nT = n-1;

        while(curr <= nT)
        {
            if(nums[curr] == 0)
            {
                swap(nums[curr++], nums[nZ++]);
            }
            else if(nums[curr] == 2)
            {
                swap(nums[curr], nums[nT--]);
            }
            else
                curr++;
        }
    }
};
