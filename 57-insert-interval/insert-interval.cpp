class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        

        vector<vector<int>>result;
        int insertIndex = 0;
        int n = intervals.size();
        bool inserted = false;

        // Case 1: intervals[0] is greater than newInterval
        if(intervals.empty() || (!intervals.empty() && newInterval[1] < intervals[0][0]))
        {
            result.push_back(newInterval);
            inserted = true;
            insertIndex = n;
        }

        // finding where to insert index
        for(int i = 0 ; i < n ; i++)
        {   
            if(!inserted && newInterval[0] <= intervals[i][1])
            {
                break;
            }
            result.push_back(intervals[i]);
            insertIndex++;
        }

        if(!inserted) {
            result.push_back(newInterval);
        }
        for(int i = insertIndex ; i < n ; i++)
        {
            if(!result.empty() && result.back()[1] >= intervals[i][0])
            {
                result.back()[0] = min(result.back()[0], intervals[i][0]);
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};