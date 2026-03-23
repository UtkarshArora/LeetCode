class Solution {
public:
int networkDelayTime(vector<vector<int>>& times, int n, int k) {


        vector<int>timings(n+1, INT_MAX);
        timings[k] = 0;
        int count = 0;
        for(int i = 1 ; i < n ; i++)
        {
            count = 0;
            bool changed = false;
            for(vector<int>&v1 : times)
            {
                int x = v1[0], y = v1[1], w = v1[2];
                if(timings[x]!=INT_MAX)
                {
                    if(timings[y] > timings[x] + w)
                    {
                        timings[y] = timings[x] + w;
                        changed = true;
                    }
                }
            }
            if(!changed)
                break;
        }
        int ans = *max_element(timings.begin()+1, timings.end());
        return ans!=INT_MAX? ans : -1;
    }
};