class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        pq.push({0,0});
        vector<bool>inMST(n, false);
        vector<int>minDist(n, INT_MAX);
        int cost = 0;
        int edges = 0;
        while(edges < n)
        {
            pair<int,int>p = pq.top();
            pq.pop();
            int index = p.second;
            if(inMST[index]){
                continue;
            }
            cost = cost + p.first;
            inMST[index] = true;
            edges++;
            for(int i = 0 ; i < n ; i++)
            {
                if(!inMST[i])
                {
                    int dist = abs(points[i][0] - points[index][0]) + abs(points[i][1] - points[index][1]);
                    if(dist < minDist[i]){
                        minDist[i] = dist;
                        pq.push({dist, i});
                    }
                }
            }
        }
        return cost;
    }
};