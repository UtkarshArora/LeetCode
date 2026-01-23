class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m-1, mid = -1;
        int row = -1;
        while(start <= end)
        {
            mid = start + (end-start)/2;
            if(matrix[mid][0] <= target && matrix[mid][n-1] >= target)
            {
                row = mid;
                break;
            }
            else if(matrix[mid][n-1] < target)
            {
                start = mid+1;
            }
            else if(matrix[mid][0] > target){
                end = mid-1;
            }
        }
        row = mid;
        start = 0, end = n-1;
        while(start <= end)
        {
            mid = start + (end - start)/2;
            if(matrix[row][mid] == target)
            {
                return true;
            }
            else if(matrix[row][mid] > target)
            {
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return false;
    }
};