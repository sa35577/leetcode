#define ll long long
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        ll pows[32];
        pows[0] = 1;
        const ll mod = 1000000007LL;
        for (int i = 1; i < 32; i++) {
            pows[i] = (pows[i-1] * (27LL)) % mod;
        }
        int sz = words[0].size();
        if (sz * words.size() > s.size()) return {};
        vector<ll> hashes;
        map<int,int> freq;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            ll tot = 0;
            for (int j = 0; j < word.size(); j++) {
                tot = (tot * (27LL)) % mod + (ll)(word[j]-'a'+1);
                tot %= mod;
            }
            hashes.push_back(tot);
            bool unique = true;
            for (int j = 0; j < i; j++) {
                if (hashes[j] == hashes[i] && words[j] == words[i]) {
                    freq[j]++;
                    unique = false;
                    break;
                }
            }
            if (unique) freq[i] = 1;
        }
        ll hash = 0;
        for (int i = 0; i < sz; i++) {
            hash = (hash * 27LL) % mod + (ll)(s[i]-'a'+1);
            hash %= mod;
        }
        vector<int> pos(s.size());
        fill(pos.begin(),pos.end(),-1);
        for (int i = 0; i < hashes.size(); i++) {
            if (hashes[i] == hash && s.substr(0,sz) == words[i]) {
                pos[0] = i;
                break;
            }
        }
        for (int i = sz; i < s.size(); i++) {
            int oldidx = i-sz;
            hash -= ((ll)(s[oldidx]-'a'+1) * pows[sz-1]) % mod;
            hash = ((hash % mod) + mod) % mod;
            hash = (hash * (27LL)) % mod;
            hash = hash + (ll)(s[i]-'a'+1);
            hash %= mod;
            for (int j = 0; j < hashes.size(); j++) {
                if (hashes[j] == hash && s.substr(oldidx+1,sz) == words[j]) {
                    pos[oldidx+1] = j;
                    break;
                }
            }
        }
        // for (int i = 0; i < pos.size(); i++) cout << pos[i] << " ";
        // cout << endl;
        vector<int> ans;
        for (int startidx = 0; startidx < sz; startidx++) {
            vector<int> v;
            int cnt = 0;
            map<int,int> mp = freq;
            int badsize = mp.size();
            for (int i = startidx; i < s.size(); i += sz) {
                cnt++;
                v.push_back(pos[i]);
                if (cnt <= words.size()) {
                    if (pos[i] != -1) {
                        mp[pos[i]]--;
                        if (mp[pos[i]] == 0) badsize--;
                        else if (mp[pos[i]] == -1) badsize++;
                    }
                }
            }
            if (badsize == 0) ans.push_back(startidx);
            for (int i = words.size(); i < v.size(); i++) {
                int oldidx = i - words.size();
                if (v[oldidx] != -1) {
                    mp[v[oldidx]]++;
                    if (mp[v[oldidx]] == 1) badsize++;
                    else if (mp[v[oldidx]] == 0) badsize--;
                }
                if (v[i] != -1) {
                    mp[v[i]]--;
                    if (mp[v[i]] == 0) badsize--;
                    else if (mp[v[i]] == -1) badsize++;
                }
                if (badsize == 0) {
                    ans.push_back((oldidx+1)*sz + startidx);
                }
            }
        }
        return ans;
    }
};