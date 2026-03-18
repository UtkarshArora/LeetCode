class Solution {
public:
    void DFS(vector<vector<char>>& grid, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();
        if (x < 0 || y < 0 || x == n || y == m || grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        DFS(grid, x + 1, y);
        DFS(grid, x - 1, y);
        DFS(grid, x, y - 1);
        DFS(grid, x, y + 1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    DFS(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};