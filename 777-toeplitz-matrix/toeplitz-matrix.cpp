class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int i = 0, j = m - 1;
        while (i < n) {
            int x = i;
            while (j >= 0) {
                cout<< i << j << endl;
                int curr_ele = arr[i][j];
                int next_i = i+1, next_j = j+1;
                while(next_i < n && next_j < m)
                {
                    int ele = arr[next_i][next_j];
                    if (ele != curr_ele) {
                        return false;
                    }
                    next_i = next_i + 1;
                    next_j = next_j + 1;
                }
                j--;
            }
            i = x;
            i++;
            j = 0;
        }
        return true;
    }
};