class LRUCache {
public:
    deque<pair<int,int>> deck; //deck<key, time>
    int time;
    int c;
    unordered_map<int,pair<int,int>> mp; //map: key -> {value,time}
    LRUCache(int capacity) {
        c = capacity;
        time = 0;
    }
    
    int get(int key) {
        time++;
        if (mp.find(key) != mp.end()) {
            deck.push_back({key,time});
            mp[key].second = time;
            // for (auto it = mp.begin(); it != mp.end(); it++) {
            //     cout << it->first << ": " << (it->second).first << " " << (it->second).second << endl;
            // }
            // cout << "-----\n";
            return mp[key].first;
        }
        // for (auto it = mp.begin(); it != mp.end(); it++) {
        //     cout << it->first << ": " << (it->second).first << " " << (it->second).second << endl;
        // }
        // cout << "-----\n";
        return -1;
        
    }
    
    void put(int key, int value) {
        time++;
        if (mp.find(key) != mp.end() || mp.size() < c) {
            mp[key] = {value,time};
            deck.push_back({key,time});
        }
        else {
            while (!deck.empty()) {
                if (mp.find(deck.front().first) != mp.end() && mp[deck.front().first].second == deck.front().second) {
                    break;
                }
                else deck.pop_front();
            }
            mp.erase(deck.front().first);
            deck.pop_front();
            mp[key] = {value,time};
            deck.push_back({key,time});
        }
        // for (auto it = mp.begin(); it != mp.end(); it++) {
        //     cout << it->first << ": " << (it->second).first << " " << (it->second).second << endl;
        // }
        // cout << "-----\n";
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */