class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int area = 0;
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    pair<int, int> p1(i, j);
                    stack<pair<int, int>> st;
                    st.push(p1);
                    int area = 0;
                    while (!st.empty()) {
                        pair<int, int> p = st.top();
                        st.pop();
                        area++;
                        maxArea = max(area, maxArea);
                        int r = p.first, c = p.second;
                        grid[r][c] = 0;
                        for (int i = 0; i < 4; i++) {
                            int nR = r + row[i];
                            int nC = c + col[i];
                            if (nR >= 0 && nR < n && nC >= 0 &&
                                nC < m && grid[nR][nC] == 1) {
                                pair<int, int> p2(nR, nC);
                                grid[nR][nC] = 0;
                                st.push(p2);
                            }
                        }
                    }
                }
            }
        }
        return maxArea;
    }
};