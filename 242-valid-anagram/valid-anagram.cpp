class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int>charCount(26,0);
        int sI = 0, tI = 0;
        while(sI < s.size() && tI < t.size())
        {
            int index = s[sI++]-'a';
            charCount[index]++;
            index = t[tI++] - 'a';
            charCount[index]--;
        }
        while(sI < s.size())
        {
            int index = s[sI++]-'a';
            charCount[index]++;
        }
        while(tI < t.size())
        {
            int index = t[tI++]-'a';
            charCount[index]--;
        }
        for(int i = 0 ; i < 26 ; i++)
        {
            if(charCount[i] != 0)
                return false;
        }
        return true;
    }
};