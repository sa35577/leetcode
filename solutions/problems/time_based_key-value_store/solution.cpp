class TimeMap {
public:
    map<string,set<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (mp.find(key) != mp.end()) {
            mp[key].insert(make_pair(-timestamp,value));
        }
        else {
            std::set<pair<int,string>> s;
            s.insert(make_pair(-timestamp,value));
            mp[key] = s;
        }
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        auto it = mp[key].lower_bound(make_pair(-timestamp,"A"));
        if (it == mp[key].end()) return "";
        pair<int,string> p = *it;
        return p.second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */