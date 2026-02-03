class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        queue<pair<int,int>>q;
        int countZeros = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j] == 0){
                    countZeros++;
                }
            }   
        }
        if(n == 0 || countZeros == m*n)
            return 0;

        if(q.empty())
            return -1;

        int count = 0;
        int minutes = -1;

        while(!q.empty())
        {
            int q_size = q.size();
            count+=q_size;
            for(int i = 0 ; i < q_size ; i++)
            {
                pair<int,int>p = q.front();
                int x = p.first, y = p.second;
                q.pop();
                for(int i = 0 ; i < 4 ; i++)
                {
                    int x_new = x + dirs[i][0];
                    int y_new = y + dirs[i][1];
                    if(x_new < 0 || x_new == n)
                        continue;
                    if(y_new < 0 || y_new == m)
                        continue;
                    if(grid[x_new][y_new] == 1){
                        q.push(make_pair(x_new, y_new));
                        grid[x_new][y_new] = 2;
                    }
                }
            }
            minutes++;
        }
        if((countZeros + count) == m*n)
        {
            return minutes;
        }
        return -1;
    }
};