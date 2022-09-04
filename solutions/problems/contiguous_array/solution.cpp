class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp;
        int sum = 0, flipper = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) flipper++;
            else flipper--;
            if (mp.find(flipper) == mp.end()) mp[flipper] = i;
            sum += nums[i];
        }
        if (sum == 0 || sum == nums.size()) return 0;
        int mx = 0;
        flipper = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) flipper++;
            else flipper--;
            if (mp.find(flipper) != mp.end() && mp[flipper] < i) {
                mx = max(mx,i-(mp[flipper]+1)+1);
            }
            if (flipper == 0) {
                mx = max(mx,i+1);
            }
        }
        return mx;
    }
};