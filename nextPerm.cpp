// main thing in approach is that at that, while finding the next permutation, don't do n^2 time complexity of finding the next smallest for each element from the end, instead find where the
// decline is, where nums[i-1] < nums[i], then from that, check for the next greatest element from nums[i-1], swap, then reverse
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int end = n-1;

        while(end > 0 && nums[end-1] >= nums[end])
        {
            end--;
        }
        if(end == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        else
        {
            int diff = INT_MAX;
            int ans = 0;
            for(int i = end; i < n ; i++)
            {
                if(nums[i] > nums[end-1])
                {
                    int sub = nums[i] - nums[end-1];
                    if(sub <= diff)
                    {
                        diff = sub;
                        ans = i;
                    }
                }
            }
            swap(nums[end-1], nums[ans]);
            reverse(nums.begin() + end, nums.end());
        }
        
    }
};
