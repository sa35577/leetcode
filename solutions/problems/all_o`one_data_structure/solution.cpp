class AllOne {
public:
    int mx,mn;
    unordered_map<string,string> deck[50005];
    unordered_map<string,int> mp;
    AllOne() {
        mx = 0, mn = 0;
    }
    
    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            mp[key] = 1;
            mx = max(mx,1);
            if (mn == 0) mn = 1;
            else mn = min(mn,1);
            deck[1][key] = key;

        }
        else {
            int nextVal = mp[key]+1;
            mp[key] = nextVal;
            mx = max(mx,nextVal);
            deck[nextVal-1].erase(key);
            deck[nextVal][key] = key;
            if (deck[nextVal-1].size() == 0 && mn == nextVal-1) mn = nextVal;
            
        }
        // cout << mn << " " << mx << endl;
    }
    
    void dec(string key) {
        int curCount = mp[key];
        if (curCount == 1) {
            mp.erase(key);
            deck[1].erase(key);
            if (mp.size() == 0) {
                mn = 0;
                mx = 0;
            }
            else {
                while (deck[mn].size() == 0) mn++;
            }
        }
        else {
            mp[key]--;
            deck[curCount].erase(key);
            curCount--;
            deck[curCount][key] = key;
            if (deck[curCount+1].size() == 0 && mx == curCount+1) {
                mx = curCount;
            }
            mn = min(mn,curCount);
       }
    //    cout << mn << " " << mx << endl;


    }
    
    string getMaxKey() {
        if (mx == 0) return "";
        return (deck[mx].begin())->first;
    }
    
    string getMinKey() {
        if (mn == 0) return "";
        return (deck[mn].begin())->first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */