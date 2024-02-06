class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // find intervals of nonzero entries. if all entries are 0, then return 0
        // say we have a window [L,R] of nonzero entries. since these are all numbers, taking the product of everything will maximize the overall product of the inside. if this product is positive, this is the best we can do. if it is not, then we need to check the first and last negative #, say at position l1 and r1. we need to take max of [L,l1-1], [l1+1,R], [L,l2-1], [l2+1,R].
        bool allneg = true;
        vector<int> zeros{-1};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeros.push_back(i);
        }
        zeros.push_back(nums.size());
        int best = INT_MIN;
        if (zeros.size() > 2) best = 0;
        for (int idx = 1; idx < zeros.size(); idx++) {
            int L = zeros[idx-1]+1, R = zeros[idx]-1;
            if (L > R) continue;
            int cntneg = 0;
            for (int i = L; i <= R; i++) {
                if (nums[i] < 0) cntneg++;
            }
            // cout << cntneg << endl;
            if (cntneg % 2 == 0) {
                int v = 1;
                for (int i = L; i <= R; i++) v *= nums[i];
                best = max(best,v);
            }
            else if (L == R) {
                best = max(best,nums[L]);
            }
            else {
                //there is at least 2 integers
                int firstneg = L, lastneg = R;
                while (nums[firstneg] > 0) firstneg++;
                while (nums[lastneg] > 0) lastneg--;
                int v1 = 1,v2 = 1, v3 = 1, v4 = 1;
                for (int i = L; i < firstneg; i++) v1 *= nums[i];
                for (int i = firstneg+1; i <= R; i++) v2 *= nums[i];
                for (int i = L; i < lastneg; i++) v3 *= nums[i];
                for (int i = lastneg+1; i <= R; i++) v4 *= nums[i];
                best = max(best,max(max(v1,v2),max(v3,v4)));
            }
        }
        return best;
        
    }
};