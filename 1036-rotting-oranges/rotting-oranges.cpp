class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>>dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        queue<pair<int,int>>q;
        int num_fresh = 0;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    pair<int,int>p = make_pair(i,j);
                    q.push(p);
                }
                else if(grid[i][j] == 1)
                {
                    num_fresh++;
                }
            }
        }
        int mins = 0;
        while(!q.empty())
        {
            int num_rotten = q.size();
            int count = 0;
            mins = mins + (int)(num_fresh > 0);
            while(count < num_rotten)
            {
                pair<int,int>p1 = q.front(); q.pop();
                for(int i = 0 ; i < 4 ; i++)
                {
                    auto [x,y] = dirs[i];
                    int x1 = p1.first + x;
                    int y1 = p1.second + y;
                    if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1] == 1)
                    {
                        q.push({x1, y1});
                        grid[x1][y1] = 2;
                        num_fresh--;
                    }
                }
                count++;
            }
        }
        return (num_fresh == 0)? mins : -1;
    }
};