class NumberContainers {
public:
    set<pair<int,int>> v;
    set<pair<int,int>> locs;
    
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        auto it = v.lower_bound(make_pair(index,-1));
        if (it != v.end()) {
            pair<int,int> p = *it;
            if (p.first == index) {
                locs.erase(make_pair(p.second,index));
                v.erase(p);
            }
        }
        locs.insert(make_pair(number,index));
        v.insert(make_pair(index,number));
    }
    
    int find(int number) {
        auto it = locs.lower_bound(make_pair(number,-1));
        if (it != locs.end()) {
            pair<int,int> p = *it;
            if (p.first == number) {
                return p.second;
            }
            return -1;
        }
        return -1;
    }
    // map<int,set<int>> mp;
    // map<int,int> v;
    // NumberContainers() {
        
    // }
    
    // void change(int index, int number) {
    //     if (v.find(index) != v.end() && v[index] != -1) {
    //         mp[v[index]].erase(index);
    //     }
    //     v[index] = number;
    //     mp[number].insert(index);
    // }
    
    // int find(int number) {
    //     if (mp.find(number) != mp.end()) {
    //         set<int> s = mp[number];
    //         auto it = s.begin();
    //         if (it == s.end()) return -1;
    //         int x = *it;
    //         return x;
    //     }
    //     return -1;
    // }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */