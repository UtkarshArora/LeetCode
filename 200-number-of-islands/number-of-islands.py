class Solution:

    def dfs(self, grid: List[List[str]], x , y) -> None:

        if x < 0 or y < 0 or x == len(grid) or y == len(grid[0]) or grid[x][y] == "0":
            return
        
        grid[x][y] = "0"
        self.dfs(grid, x-1, y)
        self.dfs(grid, x+1, y)
        self.dfs(grid, x, y-1)
        self.dfs(grid, x, y+1)

        return
            
    def numIslands(self, grid: List[List[str]]) -> int:

        n = len(grid)
        m = len(grid[0])
        ans = 0

        for i in range(n):
            for j in range(m):
                if(grid[i][j] == "1"):
                    ans+=1
                    self.dfs(grid, i, j)
        return ans
        