class LRUCache {
    int cap;
    int *buffer;
    int p;
    map<int, int> memory;
public:
    LRUCache(int capacity) {
        cap = capacity;
        buffer = new int[cap];
        p = 0;
    }
    
    int get(int key) {
        if(memory.find(key)!=memory.end())
            return memory[key];
        return -1;
    }
    
    void put(int key, int value) {
        if(memory.find(key)==memory.end()){
            if(buffer[p] != 0)
                memory.remove(buffer[p]);
            buffer[p] = key;            
            memory[key] = value;

            p = (p+1) % cap;
        }
        else{
            memory[key] = value;
            int currp = p;
            for(int i=0; i<currp-1; ++){
                if(buffer[i] = key){
                    for(int j=i+1; j<=p; ++j){
                        swap(buffer[j], buffer[j-1]);
                    }
                }
            }
        }
        
    }
};
