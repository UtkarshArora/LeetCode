class Solution {
public:

    unordered_set<int>visited;
    bool isHappy(int n) {

        if(n == 1){
            return true;
        }
        else if(visited.count(n)){
            return false;
        }
        visited.insert(n);
        int sum_sq = 0;
        while(n)
        {
            int digit = n % 10;
            sum_sq = sum_sq + (int)pow(digit, 2);
            n = n/10;
        }
        return isHappy(sum_sq);
    }
};