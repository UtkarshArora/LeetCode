class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        if(digits[n-1]!=9)
        {
            digits[n-1]++;
        }
        else
        {
            int m = n-1;
            while(m>0 && digits[m]==9)
            {
                digits[m] = 0;
                m--;
            }
            if(m == 0 && digits[m]==9)
            {
                digits[m]=1;
                digits.push_back(0);
            }
            else
                digits[m]++;
        }
        return digits;
    }
};