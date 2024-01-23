class Solution {
public:
    pair<int,int> alice[50005];
    bool alicevis[50005];
    pair<int,int> bob[50005];
    bool bobvis[50005];
    int n;
    
    pair<int,int> game(vector<int>& stones, int idx, bool isAlice) {
        if (idx == n) return {0,0};
        if (isAlice && alicevis[idx]) return alice[idx];
        else if (!isAlice && bobvis[idx]) return bob[idx]; 
        pair<int,int> g1 = game(stones,idx+1,!isAlice);
        if (isAlice) g1.first += stones[idx];
        else g1.second += stones[idx];
        if (idx+2 <= n) {
            pair<int,int> g2 = game(stones,idx+2,!isAlice);
            if (isAlice) g2.first += stones[idx] + stones[idx+1];
            else g2.second += stones[idx] + stones[idx+1];

            if (isAlice && g1.first - g1.second <= g2.first - g2.second) g1 = g2;
            else if (!isAlice && g1.second - g1.first <= g2.second - g2.first) g1 = g2;
        }
        if (idx+3 <= n) {
            pair<int,int> g3 = game(stones,idx+3,!isAlice);
            if (isAlice) g3.first += stones[idx] + stones[idx+1] + stones[idx+2];
            else g3.second += stones[idx] + stones[idx+1] + stones[idx+2];

            if (isAlice && g1.first - g1.second <= g3.first - g3.second) g1 = g3;
            else if (!isAlice && g1.second - g1.first <= g3.second - g3.first) g1 = g3;
        }
        if (isAlice) {
            alicevis[idx] = true;
            alice[idx] = g1;
            // cout << "Alice: " << idx << " " << alice[idx].first << "," << alice[idx].second << endl;
            return alice[idx];
        }
        else {
            bobvis[idx] = true;
            bob[idx] = g1;
            // cout << "Bob: " << idx << " " << bob[idx].first << "," << bob[idx].second << endl;
            return bob[idx];
        }

    }
    string stoneGameIII(vector<int>& stoneValue) {
        for (int i = 0; i < stoneValue.size()+1; i++) {
            alice[i] = {0,0};
            bob[i] = {0,0};
            alicevis[i] = false;
            bobvis[i] = false;
        }
        n = stoneValue.size();
        pair<int,int> p = game(stoneValue,0,true);
        if (p.first > p.second) return "Alice";
        else if (p.first < p.second) return "Bob";
        return "Tie";
    }
};