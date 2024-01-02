class RandomizedCollection {
public:

    unordered_map<int,int> mp;
    int total = 0;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        total++;
        if (mp.find(val) == mp.end() || mp[val] == 0) {
            mp[val] = 1;
            return true;
        }
        mp[val]++;
        return false;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end() || mp[val] == 0) return false;
        total--;
        mp[val]--;
        return true;
    }
    
    int getRandom() {
        int tot = 0;
        int idx = rand() % total;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            tot += it->second;
            if (tot > idx) return it->first;
        }
        return -1;
    }

    // multiset<int> st;
    // RandomizedCollection() {
        
    // }
    
    // bool insert(int val) {
    //     auto it = st.find(val);
    //     if (it == st.end()) {
    //         st.insert(val);
    //         return true;
    //     }
    //     st.insert(val);
    //     return false;
    // }
    
    // bool remove(int val) {
    //     auto it = st.find(val);
    //     if (it == st.end()) return false;
    //     st.erase(it);
    //     return true;
    // }
    
    // int getRandom() {
    //     auto it = st.begin();
    //     advance(it,rand() % st.size());
    //     return *it;
    // }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */