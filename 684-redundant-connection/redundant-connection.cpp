class Solution {
public:
    vector<vector<int>> createAdjMatrix(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            vector<int> v1 = edges[i];
            int x = v1[0], y = v1[1];
            adjMatrix[x][y] = 1;
            adjMatrix[y][x] = 1;
        }
        return adjMatrix;
    }

    bool checkifLoop(vector<vector<int>>& adjMatrix, int current, int parent,
                     vector<bool>& visited) {
        
        int n = adjMatrix.size();
        visited[current] = true;
        //cout<<"n:"<<n<<endl;

        for (int i = 1; i < n ; i++) {
            
            if(adjMatrix[current][i] == 1){

            if (i!= current && visited[i] && i != parent)
                return true;
            
            else if (!visited[i] && checkifLoop(adjMatrix, i, current, visited))
                return true;
            }
        }
        return false;
    }
    bool checkifLoop(vector<vector<int>>& adjMatrix) {
        int n = adjMatrix.size(); 
        vector<bool> visited(n, false);
        for (int i = 1; i < n; i++) {
            if (!visited[i]) {
                if (checkifLoop(adjMatrix, i, -1, visited))
                    return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adjMatrix = createAdjMatrix(edges);

        for (int i = n - 1; i >= 0; i--) {
            vector<int> v1 = edges[i];
            int x = v1[0], y = v1[1];
            adjMatrix[x][y] = 0;
            adjMatrix[y][x] = 0;
            bool ans = checkifLoop(adjMatrix);
            if(!ans)
                return edges[i];
            adjMatrix[x][y] = 1;
            adjMatrix[y][x] = 1;
        }
        return edges[n - 1];
    }
};