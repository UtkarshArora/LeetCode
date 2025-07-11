class Solution {
public:
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>degree(numCourses, 0);
        vector<vector<int>>adjList(numCourses);
        vector<int>ans;

        for(auto &v1 : prerequisites)
        {
            degree[v1[0]]++;
            adjList[v1[1]].push_back(v1[0]);    
        }

        queue<int>q;
        for(int i = 0; i < numCourses ; i++)
        {
            if(degree[i] == 0)
                q.push(i);
        }
        if(q.empty())
            return ans;

        while(!q.empty())
        {
            int x = q.front(); q.pop();
            ans.push_back(x);
            for(int node : adjList[x])
            {
                if(--degree[node] == 0)
                    q.push(node);
            }
        }
        return (ans.size() == numCourses)? ans : vector<int>();
    }
};