class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int max_value = INT_MIN;
        for(int num : piles)
        {
            max_value = max(max_value, num);
        }
        int ans = -1;
        int start = 1, end = max_value;
        while(start <= end)
        {
            int mid =  start + (end-start)/2;
            long long num_hours = 0;
            for(int i = 0 ; i < piles.size() ; i++)
            {
                int val = piles[i]/mid;
                if((piles[i] % mid)!=0)
                {
                    val++;
                }
                num_hours+=val;
            }
            if(num_hours <= h)
            {
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};