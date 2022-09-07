class MyHashSet {
public:
    vector<int> v[10001];
    MyHashSet() {
        
    }
    
    void add(int key) {
        int idx = key / 1000, val = key % 1000;
        for (int i = 0; i < v[idx].size(); i++) {
            if (v[idx][i] == val) return;
        }
        v[idx].push_back(val);
    }
    
    void remove(int key) {
        int idx = key / 1000, val = key % 1000;
        for (int i = 0; i < v[idx].size(); i++) {
            if (v[idx][i] == val) {
                v[idx].erase(v[idx].begin()+i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int idx = key / 1000, val = key % 1000;
        for (int i = 0; i < v[idx].size(); i++) {
            if (v[idx][i] == val) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */