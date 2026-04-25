class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int start = 0, end = n-1;
        int ans = 0;
        while(start < end)
        {
            //System.out.println(start + " " + end);
            int val = Math.min(height[start], height[end])*(end - start);
            ans = Math.max(val, ans);
            //System.out.println(val);
            if(height[start] < height[end])
                start++;
            else
                end--;
        }
        return ans;
    }
}