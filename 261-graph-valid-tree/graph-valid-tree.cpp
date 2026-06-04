class Solution {
public:

    bool isCycle(int curr, vector<vector<int>>& adjList, vector<bool>& visited, int parent)
    {
        if(visited[curr] == true && curr!=parent)
        {
            return true;
        }
        visited[curr] = true;
        for(int x : adjList[curr])
        {   
            if(x == parent){
                continue;
            }
            bool ans = isCycle(x, adjList, visited, curr);
            if(ans){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adjList(n, vector<int>());
        unordered_set<int>set1;
        for(vector<int>&edge : edges)
        {
            int x = edge[0], y = edge[1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        vector<bool>visited(n, false);
        if(isCycle(0, adjList, visited, -1))
        {
            return false;
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        return true;
    }
};