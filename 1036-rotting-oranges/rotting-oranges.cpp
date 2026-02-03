class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int countFreshOranges = 0;
        vector<pair<int,int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        int countZeros = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
                if (grid[i][j] == 1) {
                    countFreshOranges++;
                }
            }
        }
        if (n == 0 || countFreshOranges == 0)
            return 0;

        if (q.empty())
            return -1;

        int minutes = -1;

        while (!q.empty()) {

            int q_size = q.size();

            for (int i = 0; i < q_size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int x_new = x + dx;
                    int y_new = y + dy;
                    if (x_new >= 0 && x_new < n && y_new >= 0 && y_new < m &&
                        grid[x_new][y_new] == 1) {
                        q.push(make_pair(x_new, y_new));
                        grid[x_new][y_new] = 2;
                        countFreshOranges--;
                    }
                }
            }
            minutes++;
        }
        if (countFreshOranges == 0) {
            return minutes;
        }
        return -1;
    }
};