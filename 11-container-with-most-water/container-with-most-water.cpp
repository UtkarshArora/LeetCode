class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int res = 0;
    while(left < right)
    {
        int prod = (right-left)*min(height[right], height[left]);
        res = max(res, prod);
        if(height[left] < height[right])
            left++;
        else
            right--;
    }
    return res;
    }
};