class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n_rows = matrix.size(), n_cols = matrix[0].size();
        //vector<vector<bool>>visited(n, vector<bool>(m, false));
        int count = n_rows * n_cols;
        int total = 0;
        int index = 0;
        int diff = 0;
        int ele_count = n_cols;
        int num = 0;
        vector<int>ans;
        while(total < count && ele_count > 0)
        {
            while(num < ele_count && total<count)
            {
                int i = index / n_cols;
                int j = index % n_cols;
                ans.push_back(matrix[i][j]);
                index++; num++;
                total++;
            }
            // if(total == count)
            //     break;
            diff++;
            ele_count = n_rows - diff;
            num = 0;
            index--;
            while(num < ele_count && total<count)
            {
                index = index + n_cols;
                int i = index / n_cols;
                int j = index % n_cols;
                ans.push_back(matrix[i][j]);
                num++;
                total++;
            }
            // if(total == count)
            //     break;
            num = 0;
            ele_count = n_cols - diff;
            while(num < ele_count && total<count)
            {
                index--;
                int i = index / n_cols;
                int j = index % n_cols;
                ans.push_back(matrix[i][j]);
                num++;
                total++;
            }
            // if(total == ele_count)
            //     break;
            diff++;
            num = 0;
            ele_count = n_rows - diff;
            while(num < ele_count && total<count)
            {
                index = index - n_cols;
                int i = index / n_cols;
                int j = index % n_cols;
                ans.push_back(matrix[i][j]);
                num++;
                total++;
            }
            // if(total == ele_count)
            //     break;
            num = 0;
            ele_count = n_cols - diff;
            index++;
            // cout<<"curent index:"<<index<<endl;
            // cout<<"diff : "<<diff<<endl;
            // cout<<"final ele_count" << ele_count;
            // cout<<"size:"<<ans.size()<<", total:"<<total<<endl;
            // for(int num : ans)
            // {
            //     cout<<num<<" ";
            // }
            // cout<<endl;
            // cout<<"ele_count:"<<ele_count<<endl;
            // cout<<"index:"<<index<<endl;
        }
        return ans;
    }
};