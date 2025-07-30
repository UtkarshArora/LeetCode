class Solution {
public:
    int maxVowels(string s, int k) {

    auto isVowel = [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
                maxCount = max(count, maxCount);
            }
        }
        int start = 0;
        int end = k;
        while (end < s.size()) {
            if (isVowel(s[start++]))
                count--;
            if (isVowel(s[end++]))
                count++;
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};