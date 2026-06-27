class Solution {
public:

    unordered_map<int, int>memo;

    int recursiveMemo(string s, int index){

        if(index == s.size())
        {
            return 1;
        }
        if(s[index] == '0'){
            return 0;
        }
        if(memo.find(index)!=memo.end())
        {
            return memo[index];
        }
        int ans = recursiveMemo(s, index+1);
        if(index+1 < s.size() && stoi(s.substr(index, 2)) >= 10 && stoi(s.substr(index, 2)) <= 26)
        {
            ans+=recursiveMemo(s, index+2);
        }
        memo[index] = ans;
        return ans;
    }
    int numDecodings(string s) {
        return recursiveMemo(s, 0);
    }
};