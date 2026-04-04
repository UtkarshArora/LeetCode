class LRUCache {
public:

    unordered_map<int, int>map1;
    unordered_map<int, list<int>::iterator>indexes; 
    list<int>l1;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void updatePriority(int key)
    {
        auto it = indexes[key];
        l1.erase(it);  
        l1.push_back(key); // pushing back, even when updating priority
        it = prev(l1.end());
        indexes[key] = it;
    }
    void insertKey(int key, int value)
    {
        l1.push_back(key); 
        auto it = prev(l1.end());
        indexes[key] = it; 
        map1[key] = value;
    }
    int get(int key) {
        if(map1.find(key)!=map1.end()){
            updatePriority(key);
            return map1[key];
        }
        return -1;
    }
    
    void put(int key, int value) {

        if(map1.find(key)!=map1.end()){
            map1[key] = value;
            updatePriority(key);
        }
        else if(map1.size() == capacity) // more than O(n) when trying to find priority, very time consuming
        {
            auto it = l1.begin();
            int lru = *it;
            l1.erase(it);
            map1.erase(lru);
            indexes.erase(lru);
            insertKey(key, value);
        }
        else
        {
            insertKey(key, value);
        }
        return;
    }   
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */