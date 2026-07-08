class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // create an array of courses with no prereq
        // create an adjList which tells us about which courses depend on each other

        // then traverse the no prereq vector, add elements to queue, process courses which depend on them, if the course has no more prereq, add it to queue

        vector<int>preReq(numCourses, 0);
        vector<vector<int>>adjList(numCourses);
        for(vector<int>&pre : prerequisites)
        {
            adjList[pre[1]].push_back(pre[0]);
            preReq[pre[0]]++;
        }
        queue<int>q;
        for(int i = 0; i < numCourses; i++)
        {
            if(preReq[i] == 0)
            {
                q.push(i);
            }
        }
        if(q.empty()){
            return {};
        }
        vector<int>res;
        while(!q.empty())
        {
            int num = q.front(); q.pop();
            for(int course : adjList[num])
            {
                preReq[course]-=1;
                if(preReq[course] == 0){
                    q.push(course);
                }
            }
            res.push_back(num);
        }
        if(res.size() == numCourses)
        {
            return res;
        }
        return {};
    }
};