class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int start = 0, end = n - 1;
        vector<int>ans(2,0);
        while(start < end)
        {
            int sum = numbers[start] + numbers[end];
            if(sum > target)
                end--;
            else if(sum == target)
            {
                ans[0] = start+1;
                ans[1] = end+1;
                break;
            }
            else
                start++;
        }
        return ans;
    }
};