class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>charCount(26);
        for(char ch : s)
        {
            int index = ch - 'a';
            charCount[index]++;
        }
        for(char ch : t)
        {
            int index = ch - 'a';
            charCount[index]--;
        }
        for(int i = 0; i < 26 ; i++)
        {
            if(charCount[i]!= 0)
                return false;
        }
        return true;
    }
};