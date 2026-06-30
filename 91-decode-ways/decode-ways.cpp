class Solution {
public:

    int numDecHelper(string s, int index, vector<int>&memo)
    {
        if(index == s.size())
        {
            return 1;
        }
        if(s[index] == '0')
        {
            return 0;
        }
        if(memo[index]!=0){
            return memo[index];
        }
        int ans = numDecHelper(s, index+1, memo);
        if(index+1 < s.size())
        {
            int num = stoi(s.substr(index, 2));
            if(num >= 10 && num <=26)
            {
                ans+=numDecHelper(s, index+2, memo);
            }
        }
        memo[index] = ans;
        return ans;
    }
    int numDecodings(string s) {

        int len = s.size();
        vector<int>memo(len, 0);
        return numDecHelper(s, 0, memo);
    }
};