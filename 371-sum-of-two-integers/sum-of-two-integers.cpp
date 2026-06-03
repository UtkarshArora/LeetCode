class Solution {
public:
    int getSum(int a, int b) {

        vector<int>bitA(32,0);
        vector<int>bitB(32,0);

        for(int i = 31 ; i >= 0 && a!=0 ; i--)
        {
            int bit = a % 2;
            bitA[i] = bit;
            a = a / 2;
        }
        for(int i = 31; i >= 0 && b!=0 ; i--)
        {
            int bit = b%2;
            bitB[i] = bit;
            b = b / 2;
        }
        int carry = 0;
        long long int mul = 1;
        long long int finalRes = 0;
        for(int i = 31 ; i >= 0 ; i--)
        {
            int sum = bitA[i] + bitB[i] + carry;
            carry = sum/2;
            int bit = sum % 2;
            finalRes+=bit*mul;
            mul*=2;
        }
        return finalRes;
    }
};