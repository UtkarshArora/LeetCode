class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // left-> start of substring, right-> end of substring,
        // if we find a duplicate, move left to the next index of the duplicate character

        // time-> O(n), space -> O(n), n -> length of the string s

        unordered_map<char, int>charIndex; // store last occurrence of char
        int left = 0, right = 0;
        int maxlen = 0;
        while(right < s.size())
        {
            if(charIndex.find(s[right])!=charIndex.end()){
                left = max(charIndex[s[right]]+1, left);
            }   
            charIndex[s[right]] = right;
            int len = right - left + 1;
            maxlen = max(len, maxlen);
            right++;
        }
        return maxlen;
    }
};