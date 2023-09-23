class Solution {
public:
    map<int,int> mp;
    int rec(int x) {
        if (mp.find(x) != mp.end()) return mp[x];
        if (x == 1) {
            mp[1] = 0;
            return 0;
        }
        if (x % 2 == 0) {
            mp[x] = 1 + rec(x/2);
            return mp[x];
        }
        else {
            mp[x] = 1 + rec(3*x+1);
            return mp[x];
        }
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        for (int i = lo; i <= hi; i++) {
            v.push_back(make_pair(rec(i),i));
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};