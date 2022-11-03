class LRUCache {
public:
    int sz;
    int pushFront;
    int arr[400004];
    int nxt;
    pair<int,int> kv[10005]; //pair < value associted with key, index in ordering of arr >
    int cap;
    LRUCache(int capacity) {
        sz = 0;
        pushFront = 0;
        nxt = 0;
        for (int i = 0; i < 10005; i++) kv[i] = make_pair(-1,-1);
        for (int i = 0; i < 200004; i++) arr[i] = -1;
        cap = capacity;
    }
    
    int get(int key) {
        int res =  kv[key].first;
        if (res == -1) return -1;
        arr[kv[key].second] = -1;
        kv[key].second = nxt;
        arr[nxt] = key;
        nxt++;

        // for (int i = 1; i < 10; i++) {
        //     cout << kv[i].first << " ";
        // }
        // cout << endl;
        return res;
    }
    
    void put(int key, int value) {
        if (kv[key].first != -1) {
            kv[key].first = value;
            arr[kv[key].second] = -1;
            kv[key].second = nxt;
        }
        else if (sz >= cap) {
            while (arr[pushFront] == -1) pushFront++;
            kv[arr[pushFront]] = make_pair(-1,-1);
            pushFront++;
            kv[key] = make_pair(value,nxt);
        }
        else {
            kv[key] = make_pair(value,nxt);
            sz++;
        }
        arr[nxt] = key;
        nxt++;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */