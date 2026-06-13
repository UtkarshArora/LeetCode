class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        if(k == n)
        {
            return points;
        }
        vector<vector<int>>ans;
        priority_queue<pair<double,int>>pq;
        for(int i = 0 ; i < n ; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            double dist = sqrt(pow(x, 2) + pow(y, 2));
            pq.push({dist, i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        int count = 0;
        while(count < k)
        {
            pair<double,int>p1 = pq.top();
            pq.pop();
            int index = p1.second;
            ans.push_back(points[index]);
            count++;
        }
        return ans;
    }
};