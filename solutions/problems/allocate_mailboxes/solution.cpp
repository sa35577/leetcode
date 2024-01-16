typedef long long ll;
class Solution {
public:
    int getMedian(vector<int>& houses, int L, int R) {
        if ((R - L) % 2 == 0) {
            return houses[L + (R-L)/2];
        }
        return (houses[L + (R-L)/2] + houses[L + (R-L)/2 + 1]) / 2;
    }
    pair<int,ll> getScore(vector<int> &houses, int L, int R) {
        //pair<median,diff score>
        int med = getMedian(houses,L,R);
        ll score = 0;
        for (int i = L; i <= R; i++) {
            score += (ll)(abs(houses[i] - med));
        }
        return {med,score};
    }
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        vector<vector<ll>> dp(k+1);
        // vector<vector<ll>> bestMedian(k+1);
        pair<int,ll> data[101][101];
        for (int i = 0; i < houses.size(); i++) {
            for (int j = i; j < houses.size(); j++) {
                data[i][j] = getScore(houses,i,j);
            }
        }
        // vector<ll> psa{(ll)(houses[0])};
        // for (int i = 1; i < houses.size(); i++) {
            // psa.push_back(psa.back() + (ll)(houses[i]));
        // }
        for (int i = 1; i <= k; i++) {
            vector<ll> v(houses.size());
            if (i > 1) {
                for (int j = 0; j < v.size(); j++) v[j] = LLONG_MAX;
                // for (int j = 0; j < v.size(); j++) bestMedian[i].push_back(-1);
            }
            else {
                for (int j = 0; j < v.size(); j++) v[j] = data[0][j].second;
                // for (int j = 0; j < v.size(); j++) bestMedian[i].push_back(data[0][j].first);
            }
            dp[i] = v;
        }
        for (int K = 2; K <= k; K++) {
            for (int L = 0; L < houses.size(); L++) {
                for (int R = L; R < houses.size(); R++) {
                    if (L-1 >= 0 && dp[K-1][L-1] != LLONG_MAX) {
                        if (dp[K][R] > dp[K-1][L-1] + data[L][R].second) {
                            dp[K][R] = min(dp[K][R],dp[K-1][L-1] + data[L][R].second);   
                        }
                    }
                }
            }
        }
        return (int)(dp.back().back());
        
    }
};