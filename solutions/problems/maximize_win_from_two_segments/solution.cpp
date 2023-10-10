class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        vector<int> dp1; //
        for (int i = 0; i < prizePositions.size(); i++) {
            dp1.push_back(1);
        }
        int L = 0, R = 0;
        while (R+1 < prizePositions.size() && prizePositions[R+1] - prizePositions[L] <= k) {
            R++;
            dp1[R] = R-L+1;
        }
        while (L < prizePositions.size() && R < prizePositions.size()) {
            if (L == prizePositions.size()) break;
            R = max(R,L);
            dp1[R] = max(dp1[R],R-L+1);
            //if (R > 0) dp1[R] = max(dp1[R-1],dp1[R]);
            while (R+1 < prizePositions.size() && prizePositions[R+1] - prizePositions[L] <= k) {
                R++;
                dp1[R] = max(dp1[R],R-L+1);
            }
            L++;
        }
        vector<int> mxRight{dp1.back()};
        for (int i = dp1.size()-2; i >= 0; i--) {
            mxRight.push_back(max(mxRight.back(),dp1[i]));
        }
        reverse(mxRight.begin(),mxRight.end());
        R = 0;
        // int RL = 0;
        int RR = 0;
        int mx = 0;
        while (R < prizePositions.size()) {
            while (RR < prizePositions.size() && prizePositions[RR] - prizePositions[R] <= k) RR++;
            if (RR == prizePositions.size()) break;
            mx = max(mx,dp1[R] + mxRight[RR]);
            R++;
        }
        for (int x : dp1) mx = max(x,mx);
        return mx;

    }
};