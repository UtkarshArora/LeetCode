class Solution {
public:

    int expand(int left, int right, string s)
    {
        int ans = 0;
        while(left >=0 && right < s.size() && s[left] == s[right])
        {
            ans++;
            left--;
            right++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        

        int len = s.size();
        int left = 0, right = 0;
        for(int i = 0 ; i < len ; i++)
        {
            left+= expand(i, i, s);
        }
        for(int i = 0 ; i+1 < len ; i++)
        {
            right+= expand(i, i+1, s);
        }
        return left + right;
    }
};