class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0, right = 0;
        vector<int>charFreq(26,0);
        int maxFreq = 0;
        int maxLen = 0;
        char ch = '/';
        while(right < s.size())
        {
            int index = s[right] - 'A';
            charFreq[index]++;
            if(charFreq[index] >= maxFreq)
            {
                maxFreq = charFreq[index];
                ch = s[right];
            }
            int win_length = right - left + 1;
            if(win_length <= (maxFreq + k))
            {
                maxLen = max(maxLen, win_length);
            }
            else
            {
                charFreq[s[left]-'A']--;
                if(ch == s[left])
                {
                    maxFreq--;
                }
                left++;
            }
            right++;
        }
        return maxLen;
    }
};