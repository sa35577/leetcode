class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        int mxpos = -1, mnpos = -1;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (x < mn) {
                mn = x;
                mnpos = i;
            }
            if (x > mx) {
                mx = x;
                mxpos = i;
            }
        }
        int L = min(mxpos,mnpos);
        int R = max(mxpos,mnpos);
        return min(min(L+1 + (int)nums.size()-R,R+1),(int)nums.size()-L);
    }
};