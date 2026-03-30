class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>map1;
        for(string s : strs)
        {
            string s1 = s;
            sort(s1.begin(), s1.end());
            map1[s1].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto it = map1.begin(); it!=map1.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};