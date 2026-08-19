class Solution {
public:

    bool isSafe(vector<vector<int>>& graph, int node, vector<int>& safeNodes)
    {
        if(safeNodes[node] == 1){
            return true;
        }
        if(safeNodes[node] == 0){
            return false;
        }
        safeNodes[node] = 0;
        for(int index : graph[node])
        {
            bool tmp = isSafe(graph, index, safeNodes);
            if(!tmp){
                safeNodes[node] = 0;
                return false;
            }
        }
        safeNodes[node] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>safeNodes(n, -1);
        for(int i = 0 ; i < n ; i++)
        {
            if(graph[i].empty())
            {
                safeNodes[i] = 1;
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            isSafe(graph, i, safeNodes);
        }
        vector<int>res;
        for(int i = 0 ; i < n ; i++)
        {
            if(safeNodes[i] == 1){
                res.push_back(i);
            }
        }
        return res;
    }
};