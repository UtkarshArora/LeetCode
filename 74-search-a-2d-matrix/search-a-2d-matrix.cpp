class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0, end = n-1;
        int mid = -1;
        int ans = mid;
        while(start <= end)
        {
            mid = start + (end-start)/2;
            cout<<start<<endl;
            cout<<end<<endl;
            if(target == matrix[mid][0])
                return true;
            
            if(target > matrix[mid][0])
            {
                ans = mid;
                start = mid+1;
            }
            else if(target < matrix[mid][0])
            {
                end = mid - 1;
            }
        }
        if(ans == -1)
            return false;
        start = 0;
        end = m-1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(target == matrix[ans][mid])
                return true;
            else if(target > matrix[ans][mid])
                start = mid+1;
            else
                end = mid-1;
        }
        return false; 
    }
};