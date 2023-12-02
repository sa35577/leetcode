class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());
        int score = 0;
        for (int i = 0; i < piles.size()/3; i++) {
            score += piles[2*i+1];
        }
        return score;
    }
};