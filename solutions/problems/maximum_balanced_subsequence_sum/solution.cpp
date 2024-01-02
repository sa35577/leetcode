#define ll long long
class Solution {
public:
    struct Node {
        int L,R;
        ll lazy=0;
        bool done = false;
    } seg[4*100005];

    vector<pair<int,int>> data;
    ll mx = -1;

    void build_tree(int v, int L, int R) {
        seg[v].L = L;
        seg[v].R = R;
        if (L == R) return;
        int mid = (L+R)/2;
        build_tree(v*2,L,mid);
        build_tree(v*2+1,mid+1,R);
    }

    void push_lazy(int v) {
        int L = seg[v].L, R = seg[v].R;
        if (L == R || seg[v].lazy == 0) return;
        if (!seg[v*2].done) seg[v*2].lazy = max(seg[v].lazy,seg[v*2].lazy);
        if (!seg[v*2+1].done) seg[v*2+1].lazy = max(seg[v].lazy,seg[v*2+1].lazy);
        seg[v].lazy = 0LL;
    }

    ll markIndex(int v, int index) {
        int L = seg[v].L, R = seg[v].R;
        if (index < L || R < index) return LLONG_MIN;
        push_lazy(v);
        if (index == L && index == R) {
            seg[v].done = true;
            seg[v].lazy += data[index].first + data[index].second; // (nums[index]-index + index)
            mx = max(mx,seg[v].lazy);
            // cout << seg[v].lazy << " " << L << endl;
            return seg[v].lazy;
        }
        return max(markIndex(v*2,index),markIndex(v*2+1,index));
    }

    void incRange(int v, int QL, int QR, ll val) {
        int L = seg[v].L, R = seg[v].R;
        if (QR < L || R < QL || QL > QR) return;
        push_lazy(v);
        if (QL <= L && R <= QR) {
            if (!seg[v].done) seg[v].lazy = max(seg[v].lazy,val);
            return;
        }
        incRange(v*2,QL,QR,val);
        incRange(v*2+1,QL,QR,val);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            data.push_back({nums[i]-i,i});
        }
        sort(data.begin(),data.end());
        build_tree(1,0,nums.size()-1);
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(data.begin(),data.end(),make_pair(nums[i]-i,i));
            int idx = it-data.begin();
            ll off = markIndex(1,idx);
            incRange(1,idx+1,nums.size()-1,off);
        }
        bool allneg = true;
        ll maxneg = LLONG_MIN;
        for (int i : nums) {
            if (i >= 0) allneg = false;
            maxneg = max(maxneg,(ll)(i));
        }
        if (allneg) return maxneg;
        return mx;
    }
};
