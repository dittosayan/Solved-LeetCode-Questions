#define umap unordered_map

class LRUCache {
public:
    int size;
    list<int> lru;
    unordered_map<int,int> kv;
    unordered_map<int,list<int>::iterator> pointer;
    
    LRUCache(int capacity){
        size=capacity;
    }
    
    int get(int key){
        if(kv.count(key)==0)
            return -1;
        
        lru.erase(pointer[key]);
        lru.push_front(key);
        pointer[key]=lru.begin();
        
        return kv[key];
    }
    
    int put(int key,int value){
        if(lru.size()==size && kv.count(key)==0){
            kv.erase(lru.back());
            pointer.erase(lru.back());
            lru.pop_back();
        }
        
        if(kv.count(key)!=0)
            lru.erase(pointer[key]);
        
        lru.push_front(key);
        pointer[key]=lru.begin();
        
        return kv[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
