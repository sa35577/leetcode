class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,long long> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]-i) == mp.end()) mp[nums[i]-i] = 0;
            mp[nums[i]-i]++;
        }
        long long res = 0;
        long long N = (long long)(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            res += N - mp[nums[i]-i];
        }
        return res/2;

    }
};