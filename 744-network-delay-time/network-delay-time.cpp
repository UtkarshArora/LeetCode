class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>timings(n+1, INT_MAX);
        vector<vector<int>>adjMatrix(n+1, vector<int>(n+1, INT_MAX));

        for(vector<int>&v1 : times)
        {
            int x = v1[0], y = v1[1], w = v1[2];
            adjMatrix[x][y] = w;
        }
        timings[k] = 0;
        pq.push({0, k});
        while(!pq.empty())
        {
            auto [x,y] = pq.top(); pq.pop();
            for(int i = 1 ; i <= n ; i++)
            {
                if(adjMatrix[y][i]!=INT_MAX)
                {
                    int newTime = x + adjMatrix[y][i];
                    if(newTime < timings[i])
                    {
                        timings[i] = newTime;
                        pq.push({newTime, i});
                    }
                }
            }
        }
        int ans = *max_element(timings.begin()+1,timings.end());
        return ans!=INT_MAX? ans : -1;
    }
};