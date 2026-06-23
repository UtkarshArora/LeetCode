class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int numRows = matrix.size();
        int numCols = matrix[0].size();
        int currRow = 0, currCol = 0;
        vector<vector<bool>>visited(numRows, vector<bool>(numCols, false));
        int count = numRows * numCols;
        vector<int> res;
        while (count > 0) {
            while (currCol < numCols && !visited[currRow][currCol]) {
                res.push_back(matrix[currRow][currCol]);
                visited[currRow][currCol] = true;
                count--;
                currCol++;
            }
            currRow++;
            currCol--;
            while (currRow < numRows && !visited[currRow][currCol]) {
                res.push_back(matrix[currRow][currCol]);
                visited[currRow][currCol] = true;
                count--;
                currRow++;
            }
            currCol--;
            currRow--;
            while (currCol >= 0 && !visited[currRow][currCol]) {
                res.push_back(matrix[currRow][currCol]);
                visited[currRow][currCol] = true;
                count--;
                currCol--;
            }
            currCol++;
            currRow--;
            while (currRow >= 0 && !visited[currRow][currCol]) {
                res.push_back(matrix[currRow][currCol]);
                visited[currRow][currCol] = true;
                count--;
                currRow--;
            }
            currRow++;
            currCol++;
            //cout<<"count "<<count<<endl;
        }
        return res;
    }
};