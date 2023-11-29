class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MAX;
        for (int x : nums) {
            mn = min(x,mn);
        }
        int score = 0;
        for (int x : nums) {
            score += x - mn;
        }
        return score;
    }
};