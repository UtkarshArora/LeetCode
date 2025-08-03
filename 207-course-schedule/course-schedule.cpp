class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        queue<int>q;
        vector<int>numDep(numCourses);

        vector<vector<int>>adjM(numCourses);
        for(auto v1 : prerequisites)
        {
            int second = v1[1];
            int first = v1[0];
            adjM[second].push_back(first);
            numDep[first]++;
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(numDep[i] == 0)
                q.push(i);
        }
        int count = q.size();
        while(!q.empty())
        {
            int num = q.front();
            q.pop();
            for(int n : adjM[num])
            {
                numDep[n]--;
                if(numDep[n] == 0){
                    q.push(n);
                    count++;
                }
            }
        }
        return count == numCourses;
    }
};