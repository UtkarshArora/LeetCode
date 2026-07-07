class Solution {
public:

    void DFS(vector<vector<char>>& board, int x, int y)
    {
        //cout<<x<<y<<endl;
        int n = board.size();
        int m = board[0].size();
        if(x < 0 || x == n || y < 0 || y == m || board[x][y] == 'X' || board[x][y] == 'Y')
        {
            return;
        }
        board[x][y] = 'Y';
        DFS(board, x, y+1);
        DFS(board, x, y-1);
        DFS(board, x-1, y);
        DFS(board, x+1, y);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int j = 0 ; j < m ; j++)
        {
            if(board[0][j] == 'O')
            {
                DFS(board, 0, j);
            }
            if(board[n-1][j] == 'O')
            {
                DFS(board, n-1, j);
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(board[i][0] == 'O')
            {
                DFS(board, i, 0);
            }
            if(board[i][m-1] == 'O')
            {
                DFS(board, i, m-1);
            }
        }
        for(int i = 1 ; i < n-1 ; i++)
        {
            for(int j = 1 ; j < m-1 ; j++)
            {
                if(board[i][j] == 'O')
                {
                    if(board[i-1][j] == 'X' || board[i+1][j] == 'X' || board[i][j-1] == 'X' || board[i][j+1] == 'X')
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(board[i][j] == 'Y')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }   
};