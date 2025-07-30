class Solution {
public:
    int maxVowels(string s, int k) {

    auto isVowel = [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }
        int maxCount = count;
        int start = 0;
        int end = k;
        while (end < s.size()) {
            count += isVowel(s[end++]) - isVowel(s[start++]);
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};