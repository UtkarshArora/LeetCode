class Solution {
public:
    bool wordBreakHelper(string s, vector<string>& wordDict, int index, vector<int>&canBreak) {
        
        if (index == s.size()) {
            return true;
        }
        if (index > s.size()) {
            return false;
        }
        if(canBreak[index] == -1){
            return false;
        }
        
        for (string s1 : wordDict) {

            if (s[index] == s1[0]) {
                int i = 0;
                int idx = index;
                while(i < s1.size())
                {
                    if(s[idx]!=s1[i])
                    {
                        break;
                    }
                    idx++;
                    i++;
                }
                if(i == s1.size()){
                    bool ans = wordBreakHelper(s, wordDict, idx, canBreak);
                    if (ans == true) {
                        return true;
                    }
                    if(ans == false)
                    {
                        canBreak[idx] = -1;
                    }
                }
            }
        }
        canBreak[index] = -1;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        int len = s.size();
        // vector<int>canBreak(len, -2);
        // bool ans = wordBreakHelper(s, wordDict, 0, canBreak);
        // return ans;
        vector<bool>canReach(len+1);
        canReach[len] = true;
        for(int i = len-1 ; i >=0 ; i--)
        {
            for(string s1: wordDict)
            {
                int nextIdx = i + s1.size();
                if(canReach[nextIdx] == true)
                {
                    //cout<<"i:"<<i<<", nextIdx:"<<nextIdx<<endl;
                    int idx = i;
                    int start = 0;
                    while(start < s1.size())
                    {
                        if(s[idx] == s1[start])
                        {
                            start++;
                            idx++;
                        }
                        else{
                            break;
                        }
                    }
                    if(start == s1.size())
                    {
                        canReach[i] = true;
                    }
                }
                if(canReach[i] == true)
                {
                    break;
                }
            }
        }
        return canReach[0];
    }
};