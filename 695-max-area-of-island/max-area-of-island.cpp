class Solution {
public:
    int DFS(vector<vector<int>>& grid, int x, int y) {

    if (x < 0 || y < 0 || x == grid.size() || y == grid[0].size() ||
            grid[x][y] == 0){
            return 0;
        }
        grid[x][y] = 0;
       return 1 + DFS(grid, x - 1, y) + DFS(grid, x + 1, y) + DFS(grid, x, y - 1) + DFS(grid, x, y + 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int res = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int ans = DFS(grid, i, j);
                    cout<<"i:"<<i<<",j:"<<j<<",ans:"<<ans<<endl;
                    res = max(res, ans);
                }
            }
        }
        return res;
    }
};