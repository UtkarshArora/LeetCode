class TrieNode{
    
    public:

    TrieNode* links[26];
    bool isEnd;
    TrieNode()
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            links[i] = NULL;
        }
        isEnd = false;
    }
    void insertChar(int index)
    {
        this->links[index] = new TrieNode();
    }
    bool checkChar(int index)
    {
        return (this->links[index]!=NULL);
    }
};

class Trie {
public:

    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* node = root;
        for(char ch : word)
        {
            int index = ch - 'a';
            if(!node->checkChar(index))
            {
                node->insertChar(index);
            }
            node = node->links[index];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {

        TrieNode* node = root;

        for(char ch : word)
        {
            int index = ch - 'a';
            if(!node->checkChar(index))
                return false;
            node = node->links[index];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {

        TrieNode* node = root;
        for(char ch : prefix)
        {
            int index = ch - 'a';
            if(!node->checkChar(index))
                return false;
            node = node->links[index];
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