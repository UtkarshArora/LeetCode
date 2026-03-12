class Solution {
public:
    int minCost(int n) {
        if(n == 1)
            return 0;
        
        if(n%2 == 0){
            int mult = n/2;
            int prod = mult * mult;
            return prod + minCost(n/2) + minCost(n/2);
        }
        int prod = n/2 * (n/2+1);
        return prod + minCost(n/2) + minCost(n/2+1);
    }
};