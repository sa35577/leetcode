class AuthenticationManager {
public:
    set<pair<int,string>> st;
    map<string,int> mp;
    unordered_set<string> validTokens;
    int t;

    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }

    void clearOld(int currentTime) {
        while (!st.empty()) {
            pair<int,string> cur = *(st.begin());
            if (cur.first <= currentTime) {
                mp.erase(cur.second);
                st.erase(st.begin());
            }
            else return;
        }
    }
    
    void generate(string tokenId, int currentTime) {
        clearOld(currentTime);
        if (mp.find(tokenId) != mp.end()) {
            return;
        }
        mp[tokenId] = currentTime+t;
        st.insert({currentTime+t,tokenId});
        validTokens.insert(tokenId);
    }
    
    void renew(string tokenId, int currentTime) {
        clearOld(currentTime);
        if (validTokens.find(tokenId) == validTokens.end()) return;
        if (mp.find(tokenId) == mp.end()) return;
        st.erase({mp[tokenId],tokenId});
        
        mp[tokenId] = currentTime+t;
        st.insert({currentTime+t,tokenId});
    }
    
    int countUnexpiredTokens(int currentTime) {
        clearOld(currentTime);
        return st.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */