typedef long long ll;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        set<int> st;
        st.insert(-1);
        st.insert(arr.size());
        vector<pair<int,int>> v;
        for (int i = 0; i < arr.size(); i++) {
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        ll res = 0;
        const ll mod = 1000000007LL;
        for (pair<int,int> p : v) {
            int idx = p.second;
            auto itUpper = st.lower_bound(idx);
            auto itLower = itUpper;
            itLower--;
            int lo = *(itLower)+1;
            int hi = *(itUpper)-1;
            ll inc = ( (ll)(idx-lo+1) * (ll)(hi-idx+1) * (ll)(p.first) ) % mod;
            res = (res + inc) % mod;
            // cout << p.first << " " << inc << endl;
            st.insert(idx);
        }
        return (int)(res);
    }
};