class Solution {
public:
int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>>adjList(n+1);
        for(vector<int>&v1 :  times)
        {
            int index = v1[0];
            adjList[index].push_back({v1[1],v1[2]});
        }

        vector<int>timings(n+1, INT_MAX);
        timings[k] = 0;
        int count = 0;
        for(int i = 1 ; i < n ; i++)
        {
            count = 0;
            bool changed = false;
            for(int j = k ; count < n+1 ; j++)
            {
                int index = j%(n+1);
                for(auto [dest,w] : adjList[index])
                {
                    if(timings[index] == INT_MAX)
                        continue;
                    int newTime = timings[index] + w;
                    if(newTime < timings[dest])
                    {
                        timings[dest] = newTime;
                        changed = true;
                    }
                }
                count++;
            }
            if(!changed)
                break;
        }
        int ans = *max_element(timings.begin()+1, timings.end());
        return ans!=INT_MAX? ans : -1;
    }
};