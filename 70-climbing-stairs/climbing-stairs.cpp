class Solution {
public:
    int climbStairs(int n) {

        if(n<=2)
            return n;
        
        int prev_2 = 1;
        int prev = 2;
        int res = 0;
        for(int i = 3 ; i <=n ; i++)
        {
            res = prev_2 + prev;
            prev_2 = prev;
            prev = res;
        }
        return res;
    }
};