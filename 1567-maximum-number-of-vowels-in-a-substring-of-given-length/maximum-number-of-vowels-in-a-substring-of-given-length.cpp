class Solution {
public:
    int maxVowels(string s, int k) {
        // unordered_map<char, int>map1;
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' ||
                s[i] == 'u') {
                count++;
                maxCount = max(count, maxCount);
            }
        }
        int start = 0;
        int end = k;
        while (end < s.size()) {
            if (s[start] == 'a' || s[start] == 'e' || s[start] == 'o' ||
                s[start] == 'i' || s[start] == 'u')
                count--;
            if (s[end] == 'a' || s[end] == 'e' || s[end] == 'o' ||
                s[end] == 'i' || s[end] == 'u')
                count++;
            maxCount = max(count, maxCount);
            start++;
            end++;
        }
        return maxCount;
    }
};