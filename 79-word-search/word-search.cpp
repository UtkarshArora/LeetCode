class Solution {
public:

bool DFS(vector<vector<char>>& board, string word, vector<vector<bool>>&visited, int x, int y, int index)
    {
        if(x < 0 || y < 0 || x == board.size() || y == board[0].size() || visited[x][y] || word[index]!= board[x][y]){
            return false;
        }
        if(index == word.size()-1){
            return true;
        }
        visited[x][y] = true;
        bool ans = DFS(board, word, visited, x+1, y, index+1) || DFS(board, word, visited, x-1, y, index+1) || DFS(board, word, visited, x, y-1, index+1) || DFS(board, word, visited, x, y+1, index+1);

        if(ans)
        {
            return true;
        }
        visited[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size(), m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(word[0] == board[i][j])
                {
                    if(DFS(board, word, visited, i, j, 0)){
                        return true;
                    }
                    //visited[i][j] = true;
                }
            }
        }
        return false;
    }
};