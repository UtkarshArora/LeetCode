class Solution {
public:

    int numDecHelper(string s, int index)
    {
        if(index == s.size()){
            return 1;
        }
        if(s[index] == '0'){
            return 0;
        }
        int ans = numDecHelper(s, index+1);
        if(index+1 < s.size())
        {
            int num = stoi(s.substr(index, 2));

            if(num >=10 && num <=26)
            {
                ans+=numDecHelper(s, index+2);
            }
        }
        return ans;
    }
    int numDecodings(string s) {
        
        // at each index i, I check if index-1 or substring with index-2...index-1 is valid

        int len = s.size();
        vector<int>dp(len+1);
        dp[len] = 1;
        for(int i = len - 1 ; i>=0 ; i--)
        {
            if(s[i] == '0')
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = dp[i+1];
                if(i+1 < len)
                {
                    int num = stoi(s.substr(i, 2));
                    if(num >=10 && num <=26)
                    {
                        dp[i]+=dp[i+2];
                    }
                }
            }
        }
        return s.empty()? 0 : dp[0];
    }
};