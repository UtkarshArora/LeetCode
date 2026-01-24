class Solution {
public:
    bool isPalindrome(string s) {
        
        int start = 0, end = s.size() - 1;
        while(start < end)
        {
            while(start < end && !isalnum(s[start]))
                start++;
            while(start < end && !isalnum(s[end]))
                end--;
            if(start > end)
                return true;
            char ch1 = (char) tolower(s[start]);
            char ch2 = (char) tolower(s[end]);
            if(ch1!=ch2)
                return false;
            else
                {
                    start++;
                    end--;
                }
        }
        return true;
    }
};