class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>>mappings;
        vector<vector<string>>results;
        for(int i = 0 ; i < strs.size() ; i++)
        {
            string s1 = strs[i];
            sort(s1.begin(), s1.end());
            mappings[s1].push_back(strs[i]);
        }
        
        for(const auto& pair : mappings)
        {
            results.push_back(pair.second);
        }
        return results;
    }
};