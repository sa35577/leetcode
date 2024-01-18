class RandomizedSet {
public:
    unordered_map<int,int> locations;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (locations.find(val) == locations.end()) {
            locations[val] = v.size();
            v.push_back(val);
            return true;
        }
        else return false;
    }
    
    bool remove(int val) {
        if (locations.find(val) == locations.end()) return false;
        if (v.back() == val) {
            locations.erase(val);
            v.pop_back();
            return true;
        }
        int loc = locations[val];
        int currentInLast = v.back();
        // int lastIndex = v.size()-1;
        locations[currentInLast] = loc;
        v.pop_back();
        locations.erase(val);
        v[loc] = currentInLast;
        return true;
    }
    
    int getRandom() {
        int x = rand() % v.size();
        return v[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */