class Solution {
public:

    void DFS(vector<vector<int>>& isConnected, vector<bool>&visited, int x)
    {
        if(visited[x])
        {
            return;
        }
        visited[x] = true;
        for(int i = 0 ; i < isConnected.size(); i++)
        {
            if(i == x)
                continue;
            if(isConnected[x][i])
            {
                DFS(isConnected, visited, i);
            } 
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool>visited(n, false);
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
            {
                DFS(isConnected, visited, i);
                count++;
            }
        }
        return count;
    }
};