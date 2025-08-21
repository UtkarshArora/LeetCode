class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();
        int right = 0;
        int prev = INT_MIN;
        int count = 0;
        int left = 0;
        while (right + 1 < n) {
            int gap = nums[right + 1] - nums[right];
            //cout<<"gap :"<<gap<<", prev:"<<prev<<endl;
            if (prev!= gap && prev!= INT_MIN) {
                int num_ele = (right - left) + 1;
                count = count + ((num_ele - 1) * (num_ele - 2)) / 2;
                left = right;
            }
            prev = gap;
            right++;
        }
        int num_ele = right - left + 1;
        count = count + ((num_ele - 1)*(num_ele - 2))/2;
        return count;
    }
};