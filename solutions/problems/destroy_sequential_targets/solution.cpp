class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int> mp; //map: modulus -> number of elements
        int mxSize = 0;
        for (int x : nums) {
            if (mp.find(x % space) == mp.end()) {
                mp[x % space] = 1;
            }
            else mp[x % space]++;
            mxSize = max(mxSize,mp[x % space]);
        }
        int res = INT_MAX;
        for (int x : nums) {
            if (mp[x % space] == mxSize) res = min(res,x);
        }
        return res;
    }
};