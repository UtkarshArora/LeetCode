class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int>numDependencies(numCourses, 0); // how many dependencies for each course
        vector<vector<int>>reverseDep(numCourses, vector<int>()); 
        
        for(vector<int>& pre : prerequisites)
        {
            int x = pre[0], y = pre[1];
            numDependencies[x]++;
            reverseDep[y].push_back(x);
        }
        queue<int>q;
        for(int i = 0 ; i < numCourses ; i++)
        {
            if(numDependencies[i] == 0){
                q.push(i);
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            int size_q = q.size();
            ans+=size_q;
            for(int i = 0 ; i < size_q ; i++)
            {
                int course = q.front(); q.pop();
                for(int v : reverseDep[course])
                {
                    numDependencies[v]-=1;
                    if(numDependencies[v] == 0)
                    {
                        q.push(v);
                    }
                }
            }
        }
        return ans == numCourses;
    }
};