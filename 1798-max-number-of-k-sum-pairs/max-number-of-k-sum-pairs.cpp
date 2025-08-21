class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int>map1;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int num = nums[i];
            int diff = k - num;
            map1[num]++;
            if(num!= diff && map1[num] > 0 && map1[diff] > 0)
            {
                int cnt = min(map1[num],map1[diff]);
                count = count + cnt;
                map1[num] = map1[num] - cnt;
                map1[diff] = map1[diff] - cnt;
            }
            else if(num == diff && map1[num] > 1)
            {
                count++;
                map1[num] = 0;
            }
        }
        return count;
    }
};