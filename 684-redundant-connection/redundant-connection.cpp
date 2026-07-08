class Solution {
public:

    // check if loop 
    void DFS(vector<vector<int>>& adjMatrix, int x, vector<bool>& visited)
    {
        //cout<<"current:" << x<<endl;
        int n = adjMatrix.size();
        if(visited[x]){
            return;
        }
        visited[x] = true;
        for(int i = 1 ; i < n ; i++)
        {
            //cout<<"index:"<<i<<endl;
            if(adjMatrix[x][i] == 1 && !visited[i])
            {
                DFS(adjMatrix, i, visited);
            }
        }
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<vector<int>>adjMatrix(n+1, vector<int>(n+1, 0));
        for(vector<int>&v1 : edges)
        {
            int x = v1[0], y = v1[1];
            adjMatrix[x][y] = 1;
            adjMatrix[y][x] = 1;
        }
        for(int i = n-1 ; i >= 0 ; i--)
        {
            vector<int>v1 = edges[i];
            int x = v1[0], y = v1[1];
            adjMatrix[x][y] = 0;
            adjMatrix[y][x] = 0;
            vector<bool>visited(n+1, false);
            DFS(adjMatrix, x, visited);
            bool isValid = true;
            for(int i = 1 ; i <=n ; i++)
            {
                if(visited[i] == false)
                {
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                return edges[i];
            }
            adjMatrix[x][y] = 1;
            adjMatrix[y][x] = 1;
        }
        return {};
    }
};