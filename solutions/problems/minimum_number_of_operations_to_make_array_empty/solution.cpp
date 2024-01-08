class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for (int x : nums) {
            if (mp.find(x) == mp.end()) mp[x] = 0;
            mp[x]++;
        }
        int score = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int x = it->second;
            if (x <= 1) return -1;
            if (x % 3 == 0) score += x/3;
            else if ((x-2) % 3 == 0) score += (x-2)/3 + 1;
            else if ((x-4) % 3 == 0) score += (x-4)/3 + 2;
        }
        return score;
    }
};