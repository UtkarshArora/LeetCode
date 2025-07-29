class Trie {
private:
    bool compareStrings(string s1, string prefix)
    {
        if(s1.size() < prefix.size())
            return false;
        
        int index = 0;
        while(index < prefix.size())
        {
            if(s1[index] == prefix[index])
                index++;
            else
                return false;
        }
        return (index == prefix.size());
    }

public:
    vector<vector<string>>prefixes;
    //unordered_set<string>words;
    Trie() {
        prefixes.resize(26);
    }
    
    void insert(string word) {
        int index = word[0] - 'a';
        prefixes[index].push_back(word);
        // words.insert(word);
    }
    
    bool search(string word) {
        
        int index = word[0] - 'a';
        for(string& s1 : prefixes[index])
        {
            if(s1 == word)
                return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int index = prefix[0] - 'a';
        vector<string>v1 = prefixes[index];
        for(string& s : v1)
        {
            bool ans = compareStrings(s,prefix);
            if(ans)
                return ans;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */