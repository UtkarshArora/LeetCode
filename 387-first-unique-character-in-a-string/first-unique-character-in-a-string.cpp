class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>charCount(26,0);
        for(char ch : s)
        {
            int index = ch - 'a';
            charCount[index]++;
        }
        for(int i = 0 ; i < s.size() ; i++)
        {
            char ch = s[i];
            int index = ch - 'a';
            if(charCount[index] == 1)
                return i;
        }
        return -1;
    }
};