class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> atVisited(n, vector<bool>(m, false));
        vector<vector<bool>> pacVisited(n, vector<bool>(m, false));
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>>res;
        queue<pair<int, int>> atQ, pacQ;

        for (int i = 0; i < n; i++) {
            pacQ.push({i, 0});
            atQ.push({i, m - 1});
            pacVisited[i][0] = true; atVisited[i][m-1] = true;
        }
        for (int i = 0; i < m; i++) {
            pacQ.push({0, i});
            atQ.push({n - 1, i});
            pacVisited[0][i] = true; atVisited[n-1][i] = true;
        }
        while (!atQ.empty()) {
            auto [i, j] = atQ.front();
            atQ.pop();
            //atVisited[i][j] = true;
            for (int dir = 0; dir < 4; dir++) {
                int x = i + dirs[dir][0];
                int y = j + dirs[dir][1];
                if (x < 0 || x >= n || y < 0 || y >= m || atVisited[x][y] ||
                    heights[x][y] < heights[i][j])
                    continue;
                atVisited[x][y] = true;
                atQ.push({x,y});
            }
        }
        while (!pacQ.empty()) {
            auto [i, j] = pacQ.front();
            pacQ.pop();
            for (int dir = 0; dir < 4; dir++) {
                int x = i + dirs[dir][0];
                int y = j + dirs[dir][1];
                if (x < 0 || x >= n || y < 0 || y >= m || pacVisited[x][y] ||
                    heights[x][y] < heights[i][j])
                    continue;
                pacVisited[x][y] = true;
                pacQ.push({x,y});
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(atVisited[i][j] && pacVisited[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};