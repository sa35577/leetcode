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
    long long query(int endpoint, int idx) {
        if (endpoint < 0) return 0;
        int L = seg[idx].L, R = seg[idx].R;
        if (endpoint >= R) return seg[idx].val;
        if (L > endpoint) return 0;
        if (L == R) return 0;
        return query(endpoint,idx*2) + query(endpoint,idx*2+1);
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> nums3;
        for (int i = 0; i < nums1.size(); i++) {
            nums3.push_back(nums1[i]-nums2[i]);
        }
        //inequality: nums3[i] <= nums3[j] + diff
        vector<int> sortedNums = nums3;
        sort(sortedNums.begin(),sortedNums.end());
        init(0,nums1.size()-1,1);
        map<int,int> freq;
        long long cnt = 0;
        for (int i = 0; i < nums3.size(); i++) {
            auto it = upper_bound(sortedNums.begin(),sortedNums.end(),nums3[i]+diff);
            if (it == nums3.end()) {
                cnt += query(nums3.size()-1,1);
            }
            else if (it == nums3.begin()) {
                ;
            }
            else {
                int idx = it-sortedNums.begin();
                cnt += query(idx-1,1);
            }

            int curIdx = lower_bound(sortedNums.begin(),sortedNums.end(),nums3[i]) - sortedNums.begin();
            if (freq.find(nums3[i]) != freq.end()) {
                add(curIdx+freq[nums3[i]],1);
                freq[nums3[i]]++;
            }
            else {
                add(curIdx,1);
                freq[nums3[i]] = 1;
            }
            //cout << cnt << " " ;
        }
        return cnt;
    }
};