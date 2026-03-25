class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        vector<int>minDist(n, INT_MAX);
        vector<bool>inMST(n, false);
        minDist[0] = 0;
        int edges = 0;
        int cost = 0;
        while(edges < n)
        {
            int index = -1;
            int dist = INT_MAX;
            for(int i = 0 ; i < n ; i++)
            {
                if(!inMST[i] && dist > minDist[i])
                {
                    dist = minDist[i];
                    index = i;
                }
            }
            inMST[index] = true;
            cost = cost + dist;
            edges++;
            for(int i = 0 ; i < n ; i++)
            {
                if(inMST[i]){
                    continue;
                }
                int distance = abs(points[i][0] - points[index][0]) + abs(points[i][1] - points[index][1]);
                minDist[i] = min(distance, minDist[i]);
            }
        }
        return cost;
    }
};