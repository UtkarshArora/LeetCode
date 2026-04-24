class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int>map1;
        int start = 0, end = 0;
        int maxlen = 0;
        while(end < s.size())
        {
            char ch = s[end];
            if(map1.find(ch)!=map1.end())
            {
                start = max(start, map1[ch] + 1);
            }
            map1[ch] = end;
            int len = end - start + 1;
            maxlen = max(len, maxlen);
            end++;
        }
        return maxlen;
    }
};