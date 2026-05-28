// class TrieNode {

//     public:
//         vector<TrieNode*>trienodes;
//         bool isEnd;
    
//     TrieNode()
//     {
//         isEnd = false;
//     }
// }

class Trie {
public:

    vector<Trie*>trie;
    bool isEnd;

    Trie() {
        this->trie.resize(26);
        isEnd = false;
    }
    
    void insert(string word) {

        Trie* curr = this;
        for(int i = 0 ; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if(curr->trie[index] == NULL)
            {
                curr->trie[index] = new Trie();
            }
            curr = curr->trie[index];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        
        Trie* curr = this;
        for(int i = 0 ; i < word.size() ; i++)
        {
            int index = word[i] - 'a';
            if(curr->trie[index])
            {
                curr = curr->trie[index];
            }
            else
            {
                return false;
            }
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        
        Trie* curr = this;
        for(int i = 0 ; i < prefix.size() ; i++)
        {
            int index = prefix[i] - 'a';
            if(curr->trie[index]!=NULL)
            {
                curr = curr->trie[index];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */