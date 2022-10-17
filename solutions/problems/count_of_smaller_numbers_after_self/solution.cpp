#include <algorithm>
class Solution {
    struct SegNode {
        int L,R;
        int val;
    };
    SegNode seg[4*100005];
    void init(int l, int r, int idx) {
        seg[idx].val = 0;
        seg[idx].L = l;
        seg[idx].R = r;
        if (l == r) return;
        int mid = (l+r)/2;
        init(l,mid,2*idx);
        init(mid+1,r,2*idx+1);
    }
    void add(int loc, int idx) {
        int L = seg[idx].L, R = seg[idx].R;
        if (loc < L || loc > R) return;
        seg[idx].val++;
        if (L == R) return;
        int mid = (L+R)/2;
        if (loc <= mid) add(loc,idx*2);
        else add(loc,idx*2+1);
    }
    int query(int endpoint, int idx) {
        if (endpoint < 0) return 0;
        int L = seg[idx].L, R = seg[idx].R;
        if (endpoint >= R) return seg[idx].val;
        if (L > endpoint) return 0;
        if (L == R) return 0;
        return query(endpoint,idx*2) + query(endpoint,idx*2+1);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> v,sortedNums;
        for (int x : nums) v.push_back(0);
        multiset<int> s;
        map<int,int> freq;
        sortedNums = nums;
        sort(sortedNums.begin(),sortedNums.end());
        init(0,nums.size()-1,1);
        for (int i = nums.size()-1; i >= 0; i--) {
            int idx = lower_bound(sortedNums.begin(),sortedNums.end(),nums[i]) - sortedNums.begin();
            v[i] = query(idx-1,1);
            if (freq.find(v[i]) == freq.end()) {
                add(idx+freq[v[i]],1);
                freq[v[i]]++;
            }
            else {
                add(idx,1);
                freq[v[i]] = 1;
            }
        }
        return v;




        // s.insert(nums.back());
        // for (int i = nums.size()-2; i >= 0; i--) {
        //     auto it = s.lower_bound(nums[i]);
        //     if (it != s.end()) {
        //         v[i] = (it-s.begin());
        //     }
        //     else {
        //         v[i] = nums.size()-i-1;
        //     }
        //     s.insert(nums[i]);
        // }
        // return v;
    }
};