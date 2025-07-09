class Solution {
public:
    vector<vector<bool>> atV, pacV;
    vector<vector<int>> ans;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size(), m = heights[0].size();
        atV = pacV = vector<vector<bool>>(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            dfs(heights, i, 0, pacV);
            dfs(heights, i, m - 1, atV);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, 0, i, pacV);
            dfs(heights, n - 1, i, atV);
        }
        return ans;
    }

    void dfs(vector<vector<int>>& heights, int i, int j,
             vector<vector<bool>>& visited) {

                int n = heights.size(), m = heights[0].size();
                if(i < 0 || i >=n || j < 0 || j >=m || visited[i][j])
                    return;

                visited[i][j] = true;

                if(atV[i][j] && pacV[i][j])
                    ans.push_back({i,j});
                
                if( i+1 < n && heights[i+1][j] >= heights[i][j])
                    dfs(heights, i+1, j, visited);

                if( i-1 >= 0 && heights[i-1][j] >= heights[i][j])
                    dfs(heights, i-1, j, visited);
                
                if( j+1 < m && heights[i][j+1] >= heights[i][j])
                    dfs(heights, i, j+1, visited);

                if( j-1 >= 0 && heights[i][j-1] >= heights[i][j])
                    dfs(heights, i, j-1, visited);
             }
};