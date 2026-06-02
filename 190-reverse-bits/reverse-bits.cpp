class Solution {
public:
    int reverseBits(int n) {
        // convert to bit representation, convert to string, reverse string, convert string to number, then return 

        vector<int>digits(32);
        int mask = 1;
        for(int i = 31 ; i >= 0 ; i--)
        {
            int bit = (n & mask) > 0 ? 1 : 0;
            //cout<<bit<<endl;
            digits[i] = bit;
            mask = mask << 1;
        }
        int start = 0, end = 31;
        while(start <= end)
        {
            int temp = digits[start];
            digits[start] = digits[end];
            digits[end] = temp;
            start++; end--;
        }
        long long int sum = 0;
        long long int mul = 1;
        for(int i = 31 ; i >=0 ; i--)
        {
            sum+= digits[i]*mul;
            mul*=2;
        }
        return sum;
    }
};