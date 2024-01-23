class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int alice = 0, bob = 0;
        vector<pair<int,int>> v;
        for (int i = 0; i < aliceValues.size(); i++) {
            v.push_back({aliceValues[i] + bobValues[i], i});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int turn = 0;
        for (int i = 0; i < v.size(); i++) {
            turn = 1-turn;
            if (turn == 1) alice += aliceValues[v[i].second];
            else bob += bobValues[v[i].second];
        }
        if (alice > bob) return 1;
        if (alice < bob) return -1;
        return 0;

        // 5 12 1 
        // 8 0 13
    }
};