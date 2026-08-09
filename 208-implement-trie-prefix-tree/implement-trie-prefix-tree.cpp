class TrieNode{

private:
    TrieNode* links[26];
    bool isEnd;

public:
    TrieNode()
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            links[i] = nullptr;
        }
        isEnd = false;
    }
    TrieNode* insertChar(char ch)
    {
        if(links[ch-'a'] == nullptr){
            links[ch-'a'] = new TrieNode();
        }
        return links[ch-'a'];
    }
    TrieNode* getNode(char ch)
    {
        return links[ch-'a'];
    }
    bool iswordEnd()
    {
        return isEnd;
    }
    void setWordEnd()
    {
        this->isEnd = true;
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
            TrieNode* newNode = node->insertChar(ch);
            node = newNode;
        }
        node->setWordEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word)
        {
            TrieNode* nextNode = node->getNode(ch);
            if(nextNode == nullptr)
            {
                return false;
            }
            node = nextNode;
        }
        return node->iswordEnd();
    }
    
    bool startsWith(string prefix) {

        TrieNode* node = root;
        for(char ch : prefix)
        {
            TrieNode* nextNode = node->getNode(ch);
            if(nextNode == nullptr)
            {
                return false;
            }
            node = nextNode;
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