class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        //[[2,1,1],[2,3,1],[3,4,1],[2,4,0]]

        vector<vector<int>>adjMatrix(n + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < times.size(); i++) {
            vector<int>v1 = times[i];
            adjMatrix[v1[0]][v1[1]] = v1[2];
        }

        int totalEdges = n * (n - 1);
        int count = 0;
        vector<int>dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        pq.push(k);
        while(!pq.empty()) {
    
            bool timeChanged = false;
            int index = pq.top(); 
            pq.pop();
            
            for (int i = 1; i <= n; i++) {
                if (adjMatrix[index][i]!=-1) {
                    if (dist[i] > dist[index] + adjMatrix[index][i]) {
                        dist[i] = dist[index] + adjMatrix[index][i];
                        timeChanged = true;
                        pq.push(i);
                    }
                }
            }
            count++;
        }
        int maxVal = 0;
        for(int i = 1; i <=n ; i++)
        {
            if(dist[i] == INT_MAX)
            {
                return -1;
            }
            maxVal = max(maxVal, dist[i]);
        }
        return maxVal;
    }
};