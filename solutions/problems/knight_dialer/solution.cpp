class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1000000007;
        map<int,vector<int>> mp;
        mp[1] = {6,8};
        mp[2] = {7,9};
        mp[3] = {4,8};
        mp[4] = {10,3,9};
        mp[5] = {};
        mp[6] = {10,1,7};
        mp[7] = {2,6};
        mp[8] = {1,3};
        mp[9] = {2,4};
        mp[10] = {4,6};
        vector<int> v{0,1,1,1,1,1,1,1,1,1,1};
        for (int i = 2; i <= n; i++) {
            vector<int> w{0};
            for (int j = 1; j <= 10; j++) {
                int score = 0;
                for (int x : mp[j]) {
                    score = (score + v[x]) % MOD;
                }
                w.push_back(score);
            }
            v = w;
        }
        int res = 0;
        for (int x : v) {
            res = (res + x) % MOD;
        }
        return res;
    }
};