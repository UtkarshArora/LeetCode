class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int>countChar(26);
        for(char ch : s)
        {
            int index = ch-'a';
            countChar[index]++;
            if(countChar[index]==2)
                return ch;
        }
        return 'a';
    }
};