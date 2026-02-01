class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int perimeter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                    int sides = 4;
                    while (!q.empty()) {
                        pair<int,int>p = q.front();
                        q.pop();
                        int x = p.first, y = p.second;
                        int sides = 4;
                        for (int i = 0; i < 4; i++) {
                            int x_new = x + dirs[i][0];
                            int y_new = y + dirs[i][1];
                            if (x_new < 0 || x_new == n)
                                continue;
                            if (y_new < 0 || y_new == m)
                                continue;
                            if (grid[x_new][y_new] == 1) {
                                sides--;
                                if (!visited[x_new][y_new]) {
                                    q.push({x_new, y_new});
                                    visited[x_new][y_new] = true;
                                }
                            }
                        }
                        perimeter += sides;
                    }
                }
            }
        }
        return perimeter;
    }
};