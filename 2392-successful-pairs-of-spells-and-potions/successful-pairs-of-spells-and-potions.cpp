class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int>answers(n, 0);
        for(int i = 0 ; i < n ; i++)
        {
            int start = 0, end = m;
            int ans = -1;
            while(start < end)
            {
                int mid = start + (end - start)/2;
                long long num = 1LL * potions[mid] * spells[i];
                if(num >= success)
                {
                    end = mid;
                    ans = mid;
                }
                else
                    start = mid+1;
            }
            if(ans == -1)
                answers[i] = 0;
            else
                answers[i] = (m - ans);
        }
        return answers;
    }
};