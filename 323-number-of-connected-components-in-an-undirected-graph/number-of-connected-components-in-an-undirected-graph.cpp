class Solution {
public:

    int findRep(vector<int>& reps, int x)
    {
        while(x!=reps[x])
        {
            x = reps[x];
        }
        return x;
    }
    int combine(vector<int>&reps, vector<int>&sizeNodes, int x, int y)
    {
        if(x == y)
        {
            return 0;
        }
        if(sizeNodes[x] < sizeNodes[y])
        {
            reps[x] = reps[y];
            sizeNodes[y]+=sizeNodes[x];
        }
        else
        {
            reps[y] = reps[x];
            sizeNodes[x]+=sizeNodes[y];
        }
        return 1;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<int>reps(n, 0);
        vector<int>sizeNodes(n, 1);
        int num_components = n;

        for(int i = 0 ; i < n ; i++)
        {
            reps[i] = i;
        }
        for(vector<int>&v1 : edges)
        {
            int x = findRep(reps, v1[0]);
            int y = findRep(reps, v1[1]);
            int val = combine(reps, sizeNodes, x, y);
            num_components-=val;
        }
        return num_components;
    }
};