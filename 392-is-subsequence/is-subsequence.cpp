class Solution {
public:

    bool isSubSeq(string s, string t, int indexS, int indexT)
    {
        if(indexS == s.size())
            return true;
        if(indexT == t.size())
            return false;
        if(s[indexS] == t[indexT])
        {
            return isSubSeq(s, t, indexS+1, indexT+1);
        }
        return isSubSeq(s, t, indexS, indexT+1);
    }
    bool isSubsequence(string s, string t) {
        
        int indexS = 0, indexT = 0;
        return isSubSeq(s, t, indexS, indexT);
    }
};