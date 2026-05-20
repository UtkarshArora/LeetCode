class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left = 0;
        unordered_map<char,int>map1;
        if(s.size() == 0)
            return 0;
            
        map1[s[0]] = 0;
        int maxlen = 1;

        for(int right = 1 ; right < s.size() ; right++)
        {
            if(map1.find(s[right])!=map1.end())
            {
                left = max(left, map1[s[right]] + 1);   
            }
            map1[s[right]] = right;
            int len = right - left + 1;
            maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};