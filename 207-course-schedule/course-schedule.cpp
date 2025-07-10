class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adjList(numCourses);
        vector<int>numDep(numCourses);
        queue<int>q;

        for(vector<int>&v : prerequisites)
        {
            int x = v[0], y = v[1];
            numDep[x]++;
            adjList[y].push_back(x);
        }
        for(int i = 0 ; i < numCourses; i++)
        {
            if(numDep[i] == 0)
                q.push(i);
        }
        if(q.empty())
            return false;
        
        int count = q.size();
        while(!q.empty())
        {
            int course = q.front(); q.pop();
            for(int num : adjList[course])
            {
                numDep[num]--;
                if(numDep[num] == 0)
                {
                    q.push(num);
                    count++;
                }
            }
        }
        return count == numCourses;
    }
};