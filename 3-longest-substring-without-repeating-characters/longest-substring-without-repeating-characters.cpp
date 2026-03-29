class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int res = 0;
        int end = 0;
        int len = s.size();
        unordered_map<char,int>map1;
        while(end < len)
        {
            char ch = s[end];
            if(map1.count(ch))
            {   
                start = max(start, map1[ch] + 1);
            }
            map1[ch] = end;
            int dist = end - start + 1;
            res = max(res, dist);
            // cout<<"start:"<<start<<",end:"<<end<<",res:"<<res<<endl;
            end++;
        }
        return res;
    }
};