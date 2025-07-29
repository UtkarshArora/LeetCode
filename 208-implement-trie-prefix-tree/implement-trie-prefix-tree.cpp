class TrieNode{

    public:
        vector<TrieNode*> next;
        bool is_word;
        TrieNode()
        {
            next.assign(26, NULL);
            this->is_word = false;
        }
};

class Trie {
public:
    vector<TrieNode*>words;
    Trie() {
        words.assign(26, NULL);
    }
    
    void insert(string word) {

        int index = word[0] - 'a';
        TrieNode* node = NULL;
        if(words[index] == NULL)
        {
            node = new TrieNode();
            words[index] = node;
        }
        else
            node = words[index];
        
        for(int i = 1 ; i < word.size() ; i++)
        {
            int index = word[i] - 'a';

            if(node->next[index] == NULL){
                node->next[index] = new TrieNode();
            }
            node = node->next[index];
        }
        node->is_word = true;
    }
    
    bool search(string word) {
        
        int index = word[0] - 'a';

        if(words[index] == NULL)
            return false;
        
        TrieNode* node = words[index];
        
        for(int i = 1 ; i < word.size() ; i++)
        {
            int index = word[i] - 'a';
            if(node->next[index] == NULL)
                return false;
            else
                node = node->next[index];
        }
        return node->is_word;
    }
    
    bool startsWith(string prefix) {
        
        int index = prefix[0] - 'a';
        if(words[index] == NULL)
            return false;
        TrieNode* node = words[index];
        
        for(int i = 1; i < prefix.size() ; i++)
        {
            int index = prefix[i] - 'a';
            node = node->next[index];
            if(node == NULL)
                return false;
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