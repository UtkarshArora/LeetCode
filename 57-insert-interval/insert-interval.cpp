class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // find index where to insert
        // insert
        // merge overlapping intervals

        int index = 0;
        vector<vector<int>>res;
        while(index < intervals.size() && newInterval[0] > intervals[index][1])
        {
            res.push_back(intervals[index]);
            index++;
        }
        res.push_back(newInterval);
        while(index < intervals.size())
        {
            if(intervals[index][0] <= res.back()[1])
            {
                res.back()[0] = min(intervals[index][0], res.back()[0]);
                res.back()[1] = max(intervals[index][1], res.back()[1]);
            }
            else
            {
                res.push_back(intervals[index]);
            }
            index++;
        }
        return res;
    }
};