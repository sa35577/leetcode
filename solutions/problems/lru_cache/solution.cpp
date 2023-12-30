class LRUCache {
public:
    int lru[10005];
    int time;
    int c;
    int op[400005];
    int kick;
    int vals[100005];
    int sz;

    LRUCache(int capacity) {
        c = capacity;
        time = 0;
        fill(lru,lru+10005,0);
        fill(op,op+400005,0);
        fill(vals,vals+100005,-1);
        kick = 0;
        sz = 0;
    }
    
    int get(int key) {
        if (vals[key] == -1) return -1;
        time++;
        lru[key] = time;
        op[time] = key;
        return vals[key];
    }
    
    void put(int key, int value) {
        time++;
        lru[key] = time;
        op[time] = key;

        if (vals[key] != -1) { //update if already in cache
            vals[key] = value;
        }

        else if (sz < c) { //if room in cache, simply add to cache
            sz++;
            vals[key] = value;
            
        }
        else { //kick
            while (true) {
                kick++;
                if (lru[op[kick]] == kick) {
                    break;
                }
            }
            //kick number in op[kick]
            vals[op[kick]] = -1;
            vals[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */