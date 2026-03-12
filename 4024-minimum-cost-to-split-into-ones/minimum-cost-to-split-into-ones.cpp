class Solution {
public:

    // int minCostOp(int n, vector<int>&v1)
    // {
    //     if(n == 1)
    //         return 0;

    //     if(v1[n]){
    //         return v1[n];
    //     }
    //     if(n%2 == 0){
    //         int mult = n/2;
    //         int prod = mult * mult;
    //         v1[n] = prod + minCost(n/2) + minCost(n/2);
    //     }
    //     else
    //     {
    //         int prod = n/2 * (n/2+1);
    //         v1[n] = prod + minCost(n/2) + minCost(n/2+1);
    //     }
    //     return v1[n];
    // }
    int minCost(int n) {
        if(n == 1)
            return 0;

        vector<int>v1(n+1,0);
        for(int i = 2; i <= n ; i++)
        {
            int prod = 1;
            if(i%2 == 0)
            {
                prod = (i/2)*(i/2);
                v1[i] = prod + v1[i/2] + v1[i/2];
            }
            else
            {
                prod = (i/2)*(i/2+1);
                v1[i] = prod + v1[i/2] + v1[i/2+1];
            }
        }
        return v1[n];
    }
};