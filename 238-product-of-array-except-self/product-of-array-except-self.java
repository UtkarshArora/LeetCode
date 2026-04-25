class Solution {
    public int[] productExceptSelf(int[] nums) {
        
        int n = nums.length;
        int[] suffix = new int[n];
        int[] ans = new int[n];
        int prod = 1;
        for(int i = n-1 ; i >=0 ; i--)
        {
            suffix[i] = prod;
            prod*=nums[i];
        }
        prod = 1;
        for(int i = 0 ; i < n ; i++)
        {
            ans[i] = prod * suffix[i];
            prod*= nums[i];
        }
        return ans;
    }
}