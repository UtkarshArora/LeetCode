class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int maxX = -1, minX = INT_MAX, maxY = -1, minY = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)
                {
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, j);
                    maxY = max(maxY, j);
                }
            }
        }
        return (maxX - minX + 1)*(maxY - minY + 1);
    }
};