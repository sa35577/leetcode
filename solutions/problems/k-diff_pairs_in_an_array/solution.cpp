class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> mp;
        for (int x : nums) {
            if (mp.find(x) == mp.end()) mp[x] = 0;
            mp[x]++;
        }
        int res = 0;
        if (k == 0) {
            for (int x : nums) {
                if (mp[x] > 1) {
                    mp.erase(x);
                    res++;
                }
            }
            return res;
        }
        for (int x : nums) {
            if (mp.find(x+k) != mp.end() && mp.find(x) != mp.end()) res += 1;
            if (mp.find(x-k) != mp.end() && mp.find(x) != mp.end()) res += 1;
            mp.erase(x);
            
        }
        return res;
    }
};