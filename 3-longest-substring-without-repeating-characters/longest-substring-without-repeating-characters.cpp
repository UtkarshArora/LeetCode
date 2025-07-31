class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>chars;
        int start = 0;
        int count = 0;
        int maxCount = 0;
        for(int current = 0; current < s.size(); current++)
        {
            char ch = s[current];
            if(chars.find(ch) == chars.end())
            {
                chars[ch] = current;
                count = (current - start) + 1;
                maxCount = max(count, maxCount);
                // cout<<current<<" "<<start<<endl;
            }
            else if(chars.find(ch)!=chars.end())
            {
                int index = chars[ch];
                if(index < start)
                {
                    count = (current - start) + 1;
                    maxCount = max(count, maxCount);
                }
                else{
                    start = index + 1;
                }
                chars.erase(ch);
                chars[ch] = current;
            }
        }
        return maxCount;
    }
};