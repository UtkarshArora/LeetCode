class Solution {
public:

    void DFS(int index, vector<vector<int>>&adjList, unordered_set<int>&visited)
    {
        if(visited.count(index))
            return;

        visited.insert(index);
        for(int x : adjList[index])
        {
            DFS(x, adjList, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adjList(n, vector<int>());
        int count = 0;
        for(vector<int>&edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        unordered_set<int>visited;
        for(int i = 0 ; i < n ; i++)
        {
            if(visited.find(i) == visited.end()){
                count++;
                DFS(i, adjList, visited);
            }
        }
        return count;
    }
};