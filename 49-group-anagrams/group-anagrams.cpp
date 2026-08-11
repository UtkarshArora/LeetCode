class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // sort each word, use that as key as hashmap, if key exists -> push into vector, otherwise create a vector with key and the given string

        //Time-> N*klogk, space -> O(N), N -> number of words, k -> average word length
        
        unordered_map<string, vector<string>>wordMap;
        vector<vector<string>>res;
        for(string word : strs)
        {
            string s1 = word;
            sort(s1.begin(), s1.end());
            wordMap[s1].push_back(word);
        } 

        for(auto p1 : wordMap){
            res.push_back(p1.second);
        }
        return res;
    }
};