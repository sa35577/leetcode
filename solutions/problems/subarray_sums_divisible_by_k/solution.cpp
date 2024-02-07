class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int mod[10005];
        memset(mod,0,sizeof(mod));
        mod[0] = 1;
        int sum = 0;
        int res = 0;
        for (int x : nums) {
            sum = ((sum + x) % k + k) % k;
            res += mod[sum];
            mod[sum]++;
        }
        return res;
    }
};