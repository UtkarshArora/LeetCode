class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size())
            return false;
        
        vector<int>countL(26);
        for(int i = 0 ; i < s.size() ; i++)
        {
            char ch = s[i];
            char ch1 = t[i];
            countL[ch-'a']++;
            countL[ch1-'a']--;
        }
        for(int i = 0 ; i < 26 ; i++)
        {
            if(countL[i]!=0)
                return false;
        }
        return true;
    }
};