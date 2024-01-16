class Solution {
public:
    vector<string> rec(string s, vector<bool>& vis, string soFar) {
        vector<string> ret;
        if (soFar.size() == s.size()) return {soFar};
        for (int i = 0; i < vis.size(); i++) {
            if (!vis[i]) {
                vis[i] = 1;
                vector<string> f = rec(s,vis,soFar+s[i]);
                vis[i] = 0;
                ret.insert(ret.end(),f.begin(),f.end());
            }
        }
        return ret;
    }
    unordered_set<string> generateOrders(string s) {
        vector<bool> vis(s.size());
        fill(vis.begin(),vis.end(),false);
        vector<string> v = rec(s,vis,"");
        unordered_set<string> st;
        for (int i = 0; i < v.size(); i++) {
            st.insert(v[i]);
        }
        return st;
    }
    int numTilePossibilities(string tiles) {
        unordered_set<string> st = generateOrders(tiles);
        unordered_set<string> finaldp;
        for (string ss : st) {
            // cout << ss << endl;
            unordered_set<string> dp,ndp;
            dp.insert("");
            ndp = dp;
            for (int i = 0; i < ss.size(); i++) {
                //ignore current tile is in the dp = ndp case and we dont clear ndp
                for (string s : dp) {
                    ndp.insert(s + ss[i]);
                }
                dp = ndp;
                // for (string s : dp) cout << s << " ";
            }
            for (string s : dp) finaldp.insert(s);
        }
        
        return finaldp.size()-1;
        
    }
};