class Solution {

    // public:
    int[][] dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};

    void DFS(int[][] heights, int i, int j, boolean[][] visited)
    {
        if(i < 0 || j < 0 || i >= heights.length || j >= heights[0].length)
            return;
        visited[i][j] = true;
        for(int num = 0 ; num < dirs.length ; num++)
        {
            int x = i + dirs[num][0];
            int y = j + dirs[num][1];
            if(x < 0 || x >= heights.length || y >= heights[0].length || y < 0)
                continue;
            if(heights[x][y] < heights[i][j])
                continue;
            if(visited[x][y] == true)
                continue;
            DFS(heights, x, y, visited);
        }
    }
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;
        boolean[][] atlantic = new boolean[n][m];
        boolean[][] pacific = new boolean[n][m];
        List<List<Integer>>ans = new ArrayList<>();

        for(int i = 0 ; i < n ; i++){
            DFS(heights, i, 0, pacific);
        }
        for(int j = 0; j < m ; j++){
            DFS(heights, 0, j, pacific);
        }
        for(int i = 0 ; i < n ; i++){
            DFS(heights, i, m-1, atlantic);
        }
        for(int j = 0 ; j < m ; j++){
            DFS(heights, n-1, j, atlantic);
        }

        for(int i = 0; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(pacific[i][j] == true && atlantic[i][j] == true)
                {
                    ans.add(List.of(i,j));
                }
            }
        }
        return ans;
    }
}