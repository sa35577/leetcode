class MyHashMap {
public:
    set<pair<int,int>> s[1001];
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int idx = key / 1000;
        pair<int,int> rm = {key,-1};
        auto it = s[idx].lower_bound(rm);
        if (it != s[idx].end()) {
            pair<int,int> rmpair = *it;
            if (rmpair.first == key) s[idx].erase(rmpair);
        }
        pair<int,int> p = {key,value};
        s[idx].insert(p);
    }
    
    int get(int key) {
        int idx = key / 1000;
        pair<int,int> rm = {key,-1};
        auto it = s[idx].lower_bound(rm);
        if (it != s[idx].end()) {
            pair<int,int> rmpair = *it;
            if (rmpair.first == key) return rmpair.second;
            else return -1;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = key / 1000;
        pair<int,int> rm = {key,-1};
        auto it = s[idx].lower_bound(rm);
        if (it != s[idx].end()) {
            pair<int,int> rmpair = *it;
            if (rmpair.first == key) s[idx].erase(rmpair);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */