const int N = 300005;
class NumArray {
public:
    
    struct Node {
        int L;
        int R;
        int sum;
    } seg[4*N];
    vector<int> curNums;

    void build_tree(int v, int L, int R, vector<int> &nums) {
        seg[v].L = L;
        seg[v].R = R;
        if (L == R) {
            seg[v].sum = nums[L];
            return;
        }
        build_tree(v*2,L,(L+R)/2,nums);
        build_tree(v*2+1,(L+R)/2+1,R,nums);
        seg[v].sum = seg[v*2].sum + seg[v*2+1].sum;
    }

    void updateTree(int v, int idx, int newVal) {
        int L = seg[v].L, R = seg[v].R;
        if (idx < L || R < idx) return;
        seg[v].sum += newVal - curNums[idx];
        if (L == R) return;
        updateTree(v*2,idx,newVal);
        updateTree(v*2+1,idx,newVal);
    }

    int queryTree(int v, int QL, int QR) {
        int L = seg[v].L, R = seg[v].R;
        if (QL <= L && R <= QR) return seg[v].sum;
        if (QR < L || R < QL) return 0;
        return queryTree(v*2,QL,QR) + queryTree(v*2+1,QL,QR);
    }

    NumArray(vector<int>& nums) {
        build_tree(1,0,nums.size()-1,nums);
        curNums = nums;
    }
    
    void update(int index, int val) {
        updateTree(1,index,val);
        curNums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return queryTree(1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */