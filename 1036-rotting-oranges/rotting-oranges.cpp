class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        int empty = 0;
        int rotten = 0;

        int timeElapsed = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {

                    pair<int, int> p1(i, j);
                    visited[i][j] = true;
                    q.push(p1);
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

                pair<int, int> p = q.front();

                q.pop();

                //visited[p.first][p.second]
                count--;

                for (int i = 0; i < 4; i++) {

                    int nR = p.first + row[i];

                    int nC = p.second + col[i];

                    if (nR >= 0 && nR < n && nC >= 0 && nC < m &&
                        grid[nR][nC] == 1) {
                        pair<int, int> p2(nR, nC);

                        grid[nR][nC] = 2;

                        visited[nR][nC] = true;

                        q.push(p2);

                        added = true;
                    }
                }
            }
            if (added) {
                    timeElapsed++;
                    // cout<<"timeElapsed:"<<timeElapsed<<endl;
                }
        }

        int sum = empty + rotten;
        if(sum!= (m*n))
            return -1;
        
        return timeElapsed;
    }
};