typedef long long ll;
class Solution {
public:
    const ll mod = 1000000007LL;
    ll rightSum(vector<ll>& psa, vector<ll>& psaa, int L, int R) {
        // returns nums[L] + (nums[L] + nums[L+1]) + .... + (nums[L] + nums[L+1] + ... + nums[R])
        //psa = {nums[0], nums[0] + nums[1], nums[0] + nums[1] + nums[2], ...}
        //psaa = {nums[0], nums[0] + (nums[0] + nums[1]), nums[0] + (nums[0] + nums[1]) + (nums[0] + nums[1] + nums[2]), ...}
        //nums[L] + (nums[L] + nums[L+1]) + .... + (nums[R]) = psaa[R] - psaa[L-1] - (R-L+1)*psa[L-1]
        if (L == 0) return psaa[R];
        return ((psaa[R] - psaa[L-1] - ((ll)(R-L+1) * psa[L-1]) % mod) % mod + mod) % mod;
    }
    vector<ll> generatePSA(vector<ll>& v) {
        vector<ll> res{v[0] % mod};
        for (int i = 1; i < v.size(); i++) res.push_back((res.back()+v[i]) % mod);
        return res;
    }
    int totalStrength(vector<int>& strength) {
        // in range [L,R] with spot m:
        // L, L+1, ... , m left side
        // m, ..., R right side
        // total number of groups: (m-l+1)*(r-m+1)
        vector<pair<int,int>> v;
        set<int> st;
        st.insert(-1);
        st.insert(strength.size());
        vector<ll> s;
        for (int i = 0; i < strength.size(); i++) {
            v.push_back({strength[i],i});
            s.push_back((ll)(strength[i]));
        }
        
        vector<ll> psaForward = generatePSA(s);
        vector<ll> psaaForward = generatePSA(psaForward);
        // cout << "here\n";
        vector<ll> strengthsRev = s;
        // cout << "here\n";

        reverse(strengthsRev.begin(),strengthsRev.end());
        vector<ll> psaBackward = generatePSA(strengthsRev);
        vector<ll> psaaBackward = generatePSA(psaBackward);
        // cout << "here\n";
        
        sort(v.begin(),v.end());
        ll res = 0;
        for (pair<int,int> p : v) {
            int wizard = p.first, idx = p.second;
            
            auto it = st.lower_bound(idx);
            auto it2 = it;
            it2--;
            int lo = *(it2)+1;
            int hi = *(it)-1;
            //lowest value in range [lo,hi] is idx, has strength wizard = strength[idx]
            ll equalAndRight = rightSum(psaForward,psaaForward,idx,hi) % mod;
            ll left = 0;
            if (lo <= idx-1) {
                left = (left + rightSum(psaBackward,psaaBackward,strength.size()-1-(idx-1),strength.size()-1-lo)) % mod;
            }
            // cout << wizard << " " << left << " " << equalAndRight << endl;
            ll inc = ((equalAndRight * (ll)(idx-lo+1)) % mod + (left * (hi-idx+1)) % mod) % mod;
            res = (res + (inc * s[idx]) % mod) % mod;
            // cout << res << endl;
            st.insert(idx);
        }
        return res;
    }
};