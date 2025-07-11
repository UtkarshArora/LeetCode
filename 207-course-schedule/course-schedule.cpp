class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adjList(numCourses);
        vector<int>numDep(numCourses);
        queue<int>q;

        for(auto &p : prerequisites)
        {
            numDep[p[0]]++;
            adjList[p[1]].push_back(p[0]);
        }
        for(int i = 0 ; i < numCourses; i++)
        {
            if(numDep[i] == 0)
                q.push(i);
        }
        if(q.empty())
            return false;
        
        //int count = q.size();
        while(!q.empty())
        {
            int course = q.front(); q.pop();
            numCourses--;
            for(int num : adjList[course])
            {
                //numDep[num]--;
                if(--numDep[num] == 0)
                {
                    q.push(num);
                    //count++;
                }
            }
        }
        return numCourses == 0;
    }
};