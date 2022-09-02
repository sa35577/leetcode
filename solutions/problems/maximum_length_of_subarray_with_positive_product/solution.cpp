class Solution {
public:
    int solve(vector<int>& nums, int L, int R) {
        if (L == R) {
            if (nums[L] < 0) return -1;
            else return 1;
        }
        int lneg = INT_MAX, rneg = INT_MIN, cntneg = 0;
        for (int i = L; i <= R; i++) {
            if (nums[i] < 0) {
                lneg = min(lneg,i);
                rneg = max(rneg,i);
                cntneg++;
            }
        }
        if (cntneg % 2 == 0) return R-L+1;
        if (lneg == INT_MAX) return -1;
        return max(R-(lneg+1)+1,(rneg-1)-L+1);
    }
    int getMaxLen(vector<int>& nums) {
        vector<int> zeroInds;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeroInds.push_back(i);
        }
        
        if (zeroInds.size() == 0) {
            return max(0,solve(nums,0,nums.size()-1));
        }
        int lres = solve(nums,0,zeroInds[0]-1);
        for (int i = 1; i < zeroInds.size(); i++) {
            lres = max(lres,solve(nums,zeroInds[i-1]+1,zeroInds[i]-1));
        }
        lres = max(lres,solve(nums,zeroInds[zeroInds.size()-1]+1,nums.size()-1));
        return max(0,lres);
    }
};