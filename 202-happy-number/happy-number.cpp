class Solution {
public:

    unordered_set<int>set1;
    bool isHappy(int n) {

        if(n == 1)
            return true;   
        if(set1.count(n))
            return false; 
        int sum = 0;
        set1.insert(n);
        while (n!= 0) {
            int digit = n % 10;
            sum+= digit*digit;
            n = n / 10;
        }
        //cout<<sum<<endl;
        return isHappy(sum);
    }
};