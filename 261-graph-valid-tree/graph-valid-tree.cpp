class Solution {
public:

    bool isCycle(int curr, vector<vector<int>>& adjList, vector<bool>& visited, int parent, unordered_set<int>&set1)
    {
        if(visited[curr] == true && curr!=parent)
        {
            return true;
        }
        set1.insert(curr);
        visited[curr] = true;
        for(int x : adjList[curr])
        {   
            if(x == parent){
                continue;
            }
            bool ans = isCycle(x, adjList, visited, curr, set1);
            if(ans){
                return true;
            }
        }
        visited[curr] = false;
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
        if(isCycle(0, adjList, visited, -1, set1))
        {
            return false;
        }
        if(set1.size()!=n)
            return false;
        
        return true;
    }
};