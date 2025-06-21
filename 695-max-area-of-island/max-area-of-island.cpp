class Solution {
public:
    int findArea(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size())
            return 0;

        if (j < 0 || j >= grid[0].size())
            return 0;

        if (grid[i][j] != 1)
            return 0;

        if (grid[i][j] == 1) {
            grid[i][j] = -1;
            return 1 + findArea(grid, i + 1, j) + findArea(grid, i, j + 1) +
                   findArea(grid, i - 1, j) + findArea(grid, i, j - 1);
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int area = findArea(grid, i , j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};