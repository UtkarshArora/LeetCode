class Solution {
public:

    void letterCase(string s, int index, string curr, vector<string>&res)
    {
        if(index == s.size()){
            res.push_back(curr);
            return;
        }
        if(isalpha(s[index]))
        {
            string curr1 = curr;
            curr += (char)toupper(s[index]);
            letterCase(s, index+1, curr, res);
            curr1+= (char)tolower(s[index]);
            letterCase(s, index+1, curr1, res);
        }
        else{
            curr = curr + s[index];
            letterCase(s, index+1, curr, res);
        }
    }
    vector<string> letterCasePermutation(string s) {
        
        string curr = "";
        vector<string>res;
        letterCase(s, 0, curr, res);
        return res;
    }
};