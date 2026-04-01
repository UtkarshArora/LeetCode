class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int>numDep(numCourses, 0);
        vector<vector<int>>adjList(numCourses);
        int count = 0;
        for(auto v : prerequisites)
        {
            //cout<<v[0] << v[1]<<endl;
            numDep[v[0]]++;
            adjList[v[1]].push_back(v[0]);
        }
        queue<int>q;
        for(int i = 0 ; i < numCourses ; i++)
        {
            if(numDep[i] == 0){
                q.push(i);
                // cout<<i<<endl;
            }
        }
        while(!q.empty())
        {
            count++;
            int node = q.front();
            q.pop();
            //cout<<node<<" "<<count<<" "<<adjList[node].size()<<endl;
            for(int v1 : adjList[node])
            {
                numDep[v1]--;
                if(numDep[v1] == 0)
                    q.push(v1);
            }
        }
        return count == numCourses;
    }
};