class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        // brute force is O(n*n)
       
       int n = nums.size();
       //vector<int>ans(n, 0);
       int left = 0 , right = 0;
       int prod = 1;
       int prev = 0;
       while(right < n)
       {
            prod*= nums[right];
            while(prod >= k && left < right)
            {
                prod = prod / nums[left];
                left++;
            }
            if(prod < k)
            {
                int add = (right - left+1);
                if(right >= 1)
                {
                    prev = prev + add;
                }
                else
                {
                    prev = add;  
                }
            }
            right++;
       }
       return prev;
    }
};