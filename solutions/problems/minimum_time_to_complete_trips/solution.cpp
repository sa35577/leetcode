typedef long long ll;
class Solution {
public:
    long long test(vector<ll>& times, ll totalTrips, ll testTime) {
        ll res = 0;
        for (ll time : times) {
            res += testTime / time;
        }
        return res >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll L = 0LL;
        ll R = LLONG_MAX;
        vector<ll> times;
        for (int x : time) times.push_back((ll)(x));
        for (ll t : times) R = min(R,(t * (ll)(totalTrips)));
        while (L+1 < R) {
            ll mid = (L+R)/(2LL);
            if (test(times,(ll)(totalTrips),mid)) {
                R = mid;
            }
            else L = mid+1;
        }
        if (test(times,(ll)(totalTrips),L)) return L;
        return R;
    }
};