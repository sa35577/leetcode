#include <algorithm>
class Solution {
    struct SegNode {
        int L,R;
        long long val;
    };
    SegNode seg[4*50005];
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
    int query(int endpoint, int idx) { //query from left endpoint to end
        if (endpoint < 0) return 0;
        int L = seg[idx].L, R = seg[idx].R;
        if (endpoint <= L) return seg[idx].val;
        if (R < endpoint) return 0;
        if (L == R) return 0;
        return query(endpoint,idx*2) + query(endpoint,idx*2+1);
    }
public:
    int reversePairs(vector<int>& nums) {
        vector<long long> sortedNums;
        for (int x : nums) {
            sortedNums.push_back((long long)(x));
        }
        sort(sortedNums.begin(),sortedNums.end());
        init(0,nums.size()-1,1);
        map<long long,int> mp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            auto it = upper_bound(sortedNums.begin(),sortedNums.end(),2*x);
            if (it == sortedNums.begin()) {
                cnt += i;
            }
            else if (it != sortedNums.end()) {
                int pos = it - sortedNums.begin();
                cnt += query(pos,1);
            }
            int idx = lower_bound(sortedNums.begin(),sortedNums.end(),x) - sortedNums.begin();
            if (mp.find(nums[i]) != mp.end()) {
                add(idx+mp[nums[i]],1);
                mp[nums[i]]++;
            }
            else {
                add(idx,1);
                mp[nums[i]] = 1;
            }
        }
        return cnt;
    }
};