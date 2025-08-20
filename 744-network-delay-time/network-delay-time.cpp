class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int currTime = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        vector<vector<int>>adjM(n+1, vector<int>(n+1, -1));

        for(int i = 0 ; i < times.size() ; i++)
        {
            vector<int>v1 = times[i];
            int x = v1[0], y = v1[1], time = v1[2];
            adjM[x][y] = time;
        }
        pq.push({currTime,k});
        unordered_set<int>set1;
        while(!pq.empty())
        {
            auto [time,curr] = pq.top();
            pq.pop();

            if(set1.count(curr))
                continue;
            set1.insert(curr);
            currTime = time;
            for(int i = 1; i <= n ; i++)
            {
                int val = adjM[curr][i];
                if(val!= -1)
                {
                    int time = currTime + val;
                    pq.push({time, i});
                }
            }
        }
        return set1.size() == n ? currTime : -1;
    }
};