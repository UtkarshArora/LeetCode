class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int indexS = 0, indexT = 0;
        while(indexT < t.size())
        {
            if(s[indexS] == t[indexT])
            {
                indexS++;
            }
            indexT++;
        }
        return s.size() == indexS;
    }
};