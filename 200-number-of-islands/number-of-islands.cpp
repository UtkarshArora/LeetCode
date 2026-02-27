class Solution {
public:


    void DFS(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(x == -1 || x == n || y == -1 || y == m || visited[x][y] || grid[x][y] == '0')
            return;
        visited[x][y] = true;
        DFS(grid, x+1, y, visited);
        DFS(grid, x-1, y, visited);
        DFS(grid, x, y+1, visited);
        DFS(grid, x, y-1, visited);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>>visited(n, vector<bool>(m, false));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    count++;
                    DFS(grid, i, j, visited);
                }
            }
        }
        return count;
    }
};