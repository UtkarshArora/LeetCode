class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size() ;  i++)
        {
            vector<int>v = ans.back();
            if(v[1] >= intervals[i][0])
            {
                v[0] = min(v[0], intervals[i][0]);
                v[1] = max(v[1], intervals[i][1]);
                ans[ans.size()-1] = v;
            }
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};