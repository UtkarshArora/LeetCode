class Solution {
public:

    bool isValid(int x, int y, int n, int m)
    {
        return x >=0 && x < n && y >=0 && y < m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        // BFS, O(m*n)
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>>dirs = {{-1,0}, {1, 0}, {0, -1}, {0,1}};

        queue<pair<int,int>>rotten;
        int freshOranges = 0, rottenOranges = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)
                {
                    freshOranges++;
                }
                if(grid[i][j] == 2)
                {
                    rotten.push({i,j});
                    rottenOranges++;
                }
            }
        }
        int total = freshOranges + rottenOranges;
        int mins = 0;
        while(!rotten.empty())
        {
            int num_rotten = rotten.size();
            bool pushed = false;
            for(int i = 0 ; i < num_rotten ; i++){
                pair<int,int>p = rotten.front();
                rotten.pop();
                int x = p.first, y = p.second;
                for(int dir = 0 ; dir < 4 ; dir++)
                {
                    int new_x = x + dirs[dir][0];
                    int new_y = y + dirs[dir][1];
                    if(isValid(new_x, new_y, n, m) && grid[new_x][new_y] == 1)
                    {
                        rotten.push({new_x, new_y});
                        grid[new_x][new_y] = 2;
                        rottenOranges++;
                        pushed = true;
                    }
                }
            }
            mins = mins + (pushed == true);
        }
        return rottenOranges == total ? mins : -1;
    }
};