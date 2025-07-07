class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int start = 0, end = n - 1 ;
        int row = -1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(target == matrix[mid][0])
            {
                return true;
            }
            else if(target > matrix[mid][0]){
                start = mid+1;
                row = mid;
            }
            else
                end = mid-1;
        }
        if(row == -1)
            return false;
        int m = matrix[row].size();
        start = 0;
        end = m - 1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(target == matrix[row][mid])
            {
                return true;
            }
            else if(target > matrix[row][mid])
            {
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return false;
    }
};