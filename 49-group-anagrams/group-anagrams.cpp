class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // sort each word, use that as key as hashmap, if key exists -> push into vector, otherwise create a vector with key and the given string

        //Time-> O(N*klogk), space -> O(N), N -> number of words, k -> average word length
        
        // 
        // unordered_map<string, vector<string>>wordMap;
        // vector<vector<string>>res;
        // for(string word : strs)
        // {
        //     string s1 = word;
        //     sort(s1.begin(), s1.end());
        //     wordMap[s1].push_back(word);
        // } 

        // for(auto p1 : wordMap){
        //     res.push_back(p1.second);
        // }
        // return res;


        // approach 2:
        unordered_map<string, vector<string>>wordMap;
        vector<vector<string>>res;

        for(string word : strs)
        {
            vector<int>charMap(26, 0);
            for(char ch : word){
                charMap[ch-'a']++;
            }
            string key = "";
            for(int i = 0 ; i < 26 ; i++)
            {
                key+= to_string(charMap[i]);
                key+='#';
            }
            wordMap[key].push_back(word);
        }
        for(auto p1 : wordMap){
            res.push_back(p1.second);
        }
        return res;
    }
};