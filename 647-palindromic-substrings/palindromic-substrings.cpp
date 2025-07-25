class Solution {
public:
    bool isPalindrome(string s1)
    {
        int start = 0, end = s1.size()-1;
        while(start <= end)
        {
            if(s1[start] != s1[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            for(int j = i ; j < s.size() ; j++)
            {
                string s1 = s.substr(i, j-i+1);
                int val = (int)isPalindrome(s1);
                count += val;
            }
        }
        return count;
    }
};