class Solution {
public:

    struct Node {
        int L,R;
        int val=0;
    } seg[4*100005];



    void build_tree(int v, int L, int R) {
        seg[v].L = L;
        seg[v].R = R;
        if (L == R) {
            return;
        }
        build_tree(v*2,L,(L+R)/2);
        build_tree(v*2+1,(L+R)/2+1,R);
    }

    int max_query(int v, int QL, int QR) {
        int L = seg[v].L, R = seg[v].R;
        if (QL <= L && R <= QR) return seg[v].val;
        if (QR < L || R < QL) return 0;
        return max(max_query(v*2,QL,QR),max_query(v*2+1,QL,QR));
    }

    void update(int v, int idx, int newval) {
        int L = seg[v].L, R = seg[v].R;
        if (idx < L || R < idx) return;
        if (L == idx && R == idx) {
            seg[v].val = max(newval,seg[v].val);
            return;
        }
        update(v*2,idx,newval);
        update(v*2+1,idx,newval);
        seg[v].val = max(seg[v*2].val,seg[v*2+1].val);
    }



    int lengthOfLIS(vector<int>& nums, int k) {
        int maxn = 100000;
        build_tree(1,1,maxn);
        for (int i : nums) {
            if (i == 1) {
                update(1,1,1);
            }
            else {
                int left = max(1,i-k);
                int right = i-1;
                int prevmx = max_query(1,left,right);
                // cout << i << ": " << prevmx << ", " << left << " " << right << endl;
                update(1,i,prevmx+1);
            }
        }
        return max_query(1,1,100000);
    }
};