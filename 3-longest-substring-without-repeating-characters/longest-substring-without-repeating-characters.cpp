class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // sliding window: time complexity : O(n), O(1) space

        int str_len = s.size();
        int start = 0, end = 0;
        unordered_map<char,int>charIndex;
        int maxlen = 0;
        while(end < str_len)
        {
            if(charIndex.find(s[end])!=charIndex.end())
            {
                start = max(charIndex[s[end]]+1, start);
            }
            charIndex[s[end]] = end;
            int len = end - start + 1;
            maxlen = max(len, maxlen);
            end++;
        } 
        return maxlen;
    }
};