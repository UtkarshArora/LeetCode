class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return nums[n-k];
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int num : nums)
        {
            if(pq.size() == k && pq.top() < num)
            {
                pq.pop();
                pq.push(num);
            }
            else if(pq.size() < k)
            {
                pq.push(num);
            }
        }
        return pq.top();
    }
};