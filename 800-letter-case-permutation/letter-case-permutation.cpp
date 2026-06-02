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
            curr = curr+ s[index];
            letterCase(s, index+1, curr, res);
            if(toupper(s[index]) == s[index])
            {
                curr1+=tolower(s[index]);
            }
            else
            {
                curr1+=toupper(s[index]);
            }
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