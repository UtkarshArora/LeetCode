//Nothing special as such, just follow the condition given in the question, and keep track of the indices
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
        
        vector<int>row1(1,1);
        
        ans.push_back(row1);
        
        for(int i = 1 ; i < numRows; i++)
        {
            vector<int>row(i+1,1);
            for(int j = 1 ; j < i ; j++)
            {
                int val = ans[i-1][j-1] + ans[i-1][j];
                row[j] = val;
            }
            ans.push_back(row);
        }
        return ans;
    }
};
