class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> result;
        int n = intervals.size();
        int start = 0;
        while (start < n && intervals[start][0] < newInterval[0]) {
            result.push_back(intervals[start]);
            start++;
        }
        // check for min and max here as well
        if (!result.empty() && newInterval[0] <= result.back()[1]) {
            result.back()[0] = min(newInterval[0], result.back()[0]);
            result.back()[1] = max(newInterval[1], result.back()[1]);
        } else {
            result.push_back(newInterval);
        }
        for (int i = start; i < n; i++) {
            vector<int> newInterval = intervals[i];
            vector<int> v1 = result.back();
            if (newInterval[0] <= v1[1]) {
                result.back()[0] = min(newInterval[0], v1[0]);
                result.back()[1] = max(newInterval[1], v1[1]);
            } else {
                result.push_back(newInterval);
            }
        }
        return result;
    }
};