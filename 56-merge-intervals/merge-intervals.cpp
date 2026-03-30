class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size() ; i++)
        {
            vector<int>v1 = intervals[i];
            if(ans.back()[1] >= v1[0])
            {
                ans.back()[0] = min(ans.back()[0], v1[0]);
                ans.back()[1] = max(ans.back()[1], v1[1]);
            }
            else
                ans.push_back(v1);
        }
        return ans;
    }
};