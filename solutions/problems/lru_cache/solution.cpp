class LRUCache {
public:
    /*
    have a time array for what transaction happened at what time
    keep a map of the last tracked time of something actually going
    */
    unordered_map<int,int> lastTime;
    pair<int,int> data[200005]; //map: time -> {key,value}
    int rem;
    int t;
    int kick;
    LRUCache(int capacity) {
        rem = capacity;
        for (int i = 0; i < 200005; i++) data[i] = {-1,-1};
        t = 0;
        kick = 0;
    }
    
    int get(int key) {
        t++;
        if (lastTime.find(key) == lastTime.end()) return -1;
        int value = data[lastTime[key]].second;
        data[t] = {key,value};
        lastTime[key] = t;
        // for (auto it = lastTime.begin(); it != lastTime.end(); it++) {
        //     cout << it->first << ": " << it->second << endl;
        // }
        // cout << "------\n";
        return value;
    }
    
    void put(int key, int value) {
        t++;
        if (lastTime.find(key) != lastTime.end()) {
            data[t] = {key,value};
            lastTime[key] = t;
        }
        else if (rem > 0) {
            rem--;
            data[t] = {key,value};
            lastTime[key] = t;
        }
        else {
            //rem == 0
            while (data[kick].first == -1 || lastTime.find(data[kick].first) == lastTime.end() || lastTime[data[kick].first] != kick) kick++;
            lastTime.erase(data[kick].first);
            kick++;
            data[t] = {key,value};
            lastTime[key] = t;
        }
        // for (auto it = lastTime.begin(); it != lastTime.end(); it++) {
        //     cout << it->first << ": " << it->second << endl;
        // }
        // cout << "------\n";
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */