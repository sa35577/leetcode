class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size());
        fill(dp.begin(),dp.end(),0);
        dp[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            int mx = INT_MIN;
            for (int len = 1; len <= k && i-len+1 >= 0; len++) {
                //making values from arr[i],...,arr[i-len+1] the same
                mx = max(mx,arr[i-len+1]);
                int prev = 0;
                if (i-len >= 0) prev = dp[i-len];
                dp[i] = max(dp[i],prev + mx * len);
            }
        }
        return dp.back();
    }
};