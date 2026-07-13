class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>, vector<pair<double, int>>, greater<pair<double, int>>>pq;

        vector<vector<int>>res;

        for(int i = 0 ; i < points.size() ; i++)
        {
            vector<int>v1 = points[i];
            int x = v1[0], y = v1[1];
            double val = sqrt(pow(x, 2) + pow(y, 2));
            pq.push(make_pair(val, i));
        }
        int count = 0;
        while(count < k)
        {
            pair<double, int>p1 = pq.top();
            pq.pop();
            count++;
            int index = p1.second;
            res.push_back(points[index]);
        }
        return res;
    }
};