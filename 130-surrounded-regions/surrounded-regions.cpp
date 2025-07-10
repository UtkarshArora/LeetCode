class Solution {
public:
    void DFS(vector<vector<bool>>& visited, int i, int j,
             vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        if (i < 0 || i == n || j < 0 || j == m || visited[i][j]) {
            return;
        }
        visited[i][j] = true;

        if ((i + 1) < n && board[i + 1][j] == 'O') {
            DFS(visited, i + 1, j, board);
        }
        if ((i - 1) >= 0 && board[i - 1][j] == 'O') {
            DFS(visited, i - 1, j, board);
        }
        if ((j - 1) >= 0 && board[i][j - 1] == 'O') {
            DFS(visited, i, j - 1, board);
        }
        if ((j + 1) < m && board[i][j + 1] == 'O') {
            DFS(visited, i, j + 1, board);
        }
        return;
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                DFS(visited, 0, j, board);

            if (board[n-1][j] == 'O')
                DFS(visited, n - 1, j, board);
        }
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                DFS(visited, i, 0, board);

            if (board[i][m-1] == 'O')
                DFS(visited, i, m - 1, board);
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};