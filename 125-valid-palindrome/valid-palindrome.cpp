class Solution {
public:
    bool isPalindrome(string s) {
        
        int start = 0, end = s.size()-1;
        while(start < end)
        {
            if(!isalnum(s[start]))
                start++;
            else if(!isalnum(s[end]))
                end--;
            else 
            {
                if(isalpha(s[start]) && isalpha(s[end]))
                {
                    char ch1 = (char)tolower(s[start]);
                    char ch2 = (char)tolower(s[end]);
                    if(ch1 == ch2)
                    {
                        start++;
                        end--;
                    }
                    else
                        return false;
                }
                else if(s[start] == s[end])
                    {
                        start++;
                        end--;
                    }
                else
                    return false;
            }
        }
        return true;
    }
};