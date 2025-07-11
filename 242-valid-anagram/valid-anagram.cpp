class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int>counts;
        int sI = 0, tI = 0;
        while(sI < s.size())
        {
            counts[s[sI++]]++;
        }
        while(tI < t.size())
        {
            counts[t[tI++]]--;
        }
        for(auto count : counts)
            {
                if(count.second) 
                    return false;
            }
        return true;
    }
};