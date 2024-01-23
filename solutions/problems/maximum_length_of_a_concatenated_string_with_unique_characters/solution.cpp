class Solution {
public:
    int mx(vector<string>& arr, int idx, vector<bool>& vis, int sz) {
        if (idx == arr.size()) return sz;
        int skip = mx(arr,idx+1,vis,sz);
        bool bad = false;
        for (char c : arr[idx]) {
            if (vis[c-'a']) {
                bad = true;
                break;
            }
        }
        if (!bad) {
            for (char c : arr[idx]) {
                vis[c-'a'] = true;
            }
            int use = mx(arr,idx+1,vis,sz+arr[idx].size());
            for (char c : arr[idx]) {
                vis[c-'a'] = false;
            }
            return max(use,skip);
        }
        else {
            return skip;
        }
    }
    int maxLength(vector<string>& arr) {
        vector<string> unique;
        for (string s : arr) {
            vector<bool> freq(26);
            fill(freq.begin(),freq.end(),false);
            bool bad = false;
            for (char c : s) {
                if (freq[c-'a']) {
                    bad = true;
                    break;
                }
                else freq[c-'a'] = 1;
            }
            if (!bad) unique.push_back(s);
        }
        int idx = 0;
        vector<bool> vis(26);
        fill(vis.begin(),vis.end(),false);
        return mx(unique,0,vis,0);
    }
};