class Solution {
public:
    bool isPalindrome(string s) {

        int len = s.size();
        int start = 0, end = len - 1;

        while (start <= end) {

           if(!isalnum(s[start])){
                start++;
                continue;
           }

            if(!isalnum(s[end])){
                end--;
                continue;
            }            
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