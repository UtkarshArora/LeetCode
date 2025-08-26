class Solution {
public:
    bool isPalindrome(string s) {

        int len = s.size();
        int start = 0, end = len - 1;

        while (start <= end) {

            while (start < len && !isalnum(s[start]))
                start++;

            while (end >= 0 && !isalnum(s[end]))
                end--;

            if (start == len || end < 0)
                return true;
            
            //cout<<s[start]<<" "<<s[end]<<endl;
            if (tolower(s[start]) == tolower(s[end])) {
                start++;
                end--;
            } else
                return false;
        }
        return true;
    }
};