// using double linked list implementation. test ok, run time error.
class LRUCache {
    int cap;
    int c;
    list<pair<int,int>> dl;
    map<int, list<pair<int,int>>::iterator> memory;
public:
    LRUCache(int capacity) {
        cap = capacity;
        c = 0;
    }
    
    int get(int key) {
        if(memory.find(key)!=memory.end()){
            auto p = memory[key];
            int val = p->first;
            // remove from dl;
            dl.erase(p);
            // add into dl;
            dl.push_front(make_pair(val, key));
            // return value
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(memory.find(key) != memory.end()){
            auto p = memory[key];
            // remove from dl;
            dl.erase(p);
            // add into dl;
            dl.push_front(make_pair(value, key));
            return;
        }
        if(c==cap){  // remove one
            auto p = dl.back();
            memory.erase(p.second);
            dl.pop_back();
            c--;
        }
        dl.push_front(make_pair(value, key));
        list<pair<int,int>>::iterator f = dl.begin();
        memory[key] = f;
        c++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
