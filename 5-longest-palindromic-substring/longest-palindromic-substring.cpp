
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<bool>>dp(len, vector<bool>(len, false));
        for(int i = 0 ; i < len ; i++)
        {
            dp[i][i] = true;
        }
        int left = -1;
        int right = -1;
        for(int i = 0 ; i+1 < len ; i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                left = i;
                right = i+1;
            }
        }  
        for(int count = 2; count < len ; count++)
        {
            for(int i = 0 ; i + count < len ; i++)
            {
                int j = i + count;
                //cout<<"i:"<<i<<", j:"<<j<<endl;
                if(dp[i+1][j-1] == true && s[i] == s[j])
                {
                    dp[i][j] = true;
                    left = i;
                    right = j;
                }
            }
        }
        if(left == -1)
        {
            return string() + s[0];
        }
        return s.substr(left, right-left+1);
    }
};