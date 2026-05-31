class Solution {
public:

    static bool comparator(vector<int>&interval1, vector<int>&interval2)
    {
        return interval1[1] < interval2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comparator);
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        int count = 0;
        for(int i = 1 ; i < intervals.size() ; i++)
        {
            if(res.back()[1] <= intervals[i][0] || intervals[i][1] <= res.back()[0])
            {
                res.push_back(intervals[i]);
            }
            else{
                cout<<"index: "<<i<<endl;
            }
        }
        return (intervals.size() - res.size());
    }
};