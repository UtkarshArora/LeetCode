class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        
        vector<pair<int,int>>dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        queue<pair<int, int>> q;
        
        int empty = 0;
        int rotten = 0;

        int timeElapsed = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    visited[i][j] = true;
                    q.push({i,j});
                }
                if(grid[i][j] == 0)
                    empty++;
            }
        }
        while (!q.empty()) {

            int count = q.size();
            bool added = false;
            rotten = rotten + count;

            while (count > 0) {

                auto[x,y] = q.front();
                q.pop();
                count--;

                for (auto [dx, dy] : dirs) {

                    int nR = x + dx;
                    int nC = y + dy;

                    if (nR >= 0 && nR < n && nC >= 0 && nC < m &&
                        grid[nR][nC] == 1) {

                        grid[nR][nC] = 2;
                        visited[nR][nC] = true;
                        q.push({nR, nC});
                        added = true;
                    }
                }
            }
            timeElapsed+= added; 
        }

        int sum = empty + rotten;
        if(sum!= (m*n))
            return -1;
        
        return timeElapsed;
    }
};