class TrieNode{

    public:
        TrieNode* links[26];
        bool isEnd;

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
        if(links[ch-'a'] == nullptr)
        {
            links[ch-'a'] = new TrieNode();
        }
        return links[ch-'a'];
    }
    void setwordEnd()
    {
        this->isEnd = true;
    }
    bool iswordEnd()
    {
        return isEnd;
    }
    TrieNode* getNextNode(char ch)
    {
        return this->links[ch-'a'];
    }
};   


class WordDictionary {

    public:
        TrieNode* root;
        WordDictionary() {
            root = new TrieNode();
        }
    
    void addWord(string word) {

        TrieNode* node = root;
        for(char ch : word)
        {
            TrieNode* newNode = node->insertChar(ch);
            node = newNode;
        }
        node->setwordEnd();
    }
  
   bool DFS(TrieNode* node, string word, int index)
   {
        if(node == nullptr){
            return false;
        }
        if(index == word.size())
        {
            return node->iswordEnd();
        }
        if(word[index]!='.'){
            return DFS(node->getNextNode(word[index]), word, index+1);
        }
        for(int i = 0 ; i < 26 ; i++)
        {
            if(node->links[i]!=nullptr){
                bool ans = DFS(node->links[i], word, index+1);
                if(ans){
                    return true;
                }
            }
        }
        return false;
   }
   bool search(string word) {
      
      TrieNode* node = root;
      for(int i = 0 ; i < word.size() ; i++)
      {
        char ch = word[i];
        if(ch == '.')
        {
            return DFS(node, word, i);
        }
        else{
            TrieNode* newNode = node->getNextNode(ch);
            if(newNode == nullptr)
            {
                return false;
            }
            node = newNode;
        }
      }
      return node->iswordEnd();
   }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */