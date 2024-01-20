class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()+1);
        fill(dp.begin(),dp.end(),0LL);
        long long res = -1;
        long long prev = -1;
        for (int i = 0; i < questions.size(); i++) {
            prev = max(prev,dp[i]);
            long long newScore = prev + (long long)(questions[i][0]);
            dp[min(i + questions[i][1] + 1, (int)questions.size())] = max(dp[min(i + questions[i][1] + 1, (int)questions.size())], newScore);
            res = max(res,newScore);
        }
        return max(res,dp.back());
    }
};