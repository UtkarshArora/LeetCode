class Solution {
public:
    int reverse(int x) {
        
        bool negative = (x < 0)? true : false;
        int curr = 0;
        if(x <= INT_MIN || x >= INT_MAX)
        {
            return 0;
        }
        x = abs(x);
        while(x!=0)
        {
            int digit = x%10;

            if(curr > INT_MAX/10 )
            {
                return 0;
            }
            curr = curr*10 + digit;
            x = x/10;
        }
        if(negative)
        {
            return -curr;
        }
        return curr;
    }
};