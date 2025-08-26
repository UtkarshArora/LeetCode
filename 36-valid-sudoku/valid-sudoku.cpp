class Solution {
public:

    bool check3X3(vector<vector<char>>& board)
    {
        int n = board.size();
        for(int i = 0 ; i < n ; i = i + 3)
        {
            for(int j = 0; j < n ; j = j + 3)
            {
                int x = i;
                int y = j;
                vector<bool>visited(10, false);
                while(x < (i + 3))
                {
                    y = j;
                    while(y < (j + 3))
                    {
                        int num = board[x][y] - '0';
                        y++;
                        if(num <= 0)
                            continue;
                        //cout<<num<<endl;
                        if(visited[num] == true)
                            return false;
                        visited[num] = true;
                    }
                    x++;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n = board.size();
        if(!check3X3(board))
            return false;
        
        for(int i = 0 ; i < n ; i++)
        {
            vector<bool>visited(10, false);
            for(int j = 0 ; j < n ; j++)
            {
                if(board[i][j]== '.')
                    continue;
                int num = board[i][j] - '0';
                if(visited[num] == true)
                    return false;
                visited[num] = true;
            }
        }
        for(int j = 0 ; j < n ; j++)
        {
            vector<bool>visited(10, false);
            for(int i = 0 ; i < n ; i++)
            {
                if(board[i][j]== '.')
                    continue;
                int num = board[i][j] - '0';
                if(visited[num] == true)
                    return false;
                visited[num] = true;
            }
        }
        return true;
    }
};