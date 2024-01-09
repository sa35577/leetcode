class MapSum {
public:
    map<string,int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int score = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            string s = it->first;
            if (s.size() >= prefix.size() && s.substr(0,prefix.size()) == prefix) score += it->second;
        }
        return score;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */