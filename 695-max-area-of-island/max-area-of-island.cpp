class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        int area = 0, maxArea = 0;
        queue<pair<int,int>>q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    int area = 0;
                    while(!q.empty())
                    {
                        pair<int,int>p1 = q.front();
                        q.pop();
                        int x = p1.first, y = p1.second;
                        grid[x][y] = 0;
                        area++;
                        for(int i = 0 ; i < 4 ; i++)
                        {
                            int x_new = x + dirs[i][0];
                            int y_new = y + dirs[i][1];
                            if(x_new < 0 || x_new >= n)
                                continue;
                            if(y_new < 0 || y_new >= m)
                                continue;
                            if(grid[x_new][y_new] == 1)
                            {
                                q.push({x_new, y_new});
                                grid[x_new][y_new] = 0;
                            }
                        }
                    }
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};