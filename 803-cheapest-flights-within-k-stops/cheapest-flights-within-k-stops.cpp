class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int>distances(n, INT_MAX);
        vector<vector<pair<int,int>>>adjList(n);
        int count = 0;
        distances[src] = 0;
        while(count < k+1)
        {
            vector<int>temp = distances;
                for(auto v : flights)
                {
                    int x = v[0], y = v[1], cost = v[2];
                    if(distances[x] == INT_MAX)
                        continue;
                    if(distances[x] + cost < temp[y])
                    {
                        temp[y] = distances[x] + cost;
                    }
                }
            distances = temp;
            count++;
        }
        return distances[dst]!=INT_MAX ? distances[dst] : -1;
    }
};