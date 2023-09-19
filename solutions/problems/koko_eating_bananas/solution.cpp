class Solution {
public:
    long long hours(vector<int> &piles, long long speed) {
        long long ans = 0;
        cout << speed << endl;
        for (int pile : piles) {
            long long p = (long long)(pile);
            ans += p / speed;
            if (p % speed > 0) ans++;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long hrs = (long long)(h);
        long long L = 1;
        long long R = 100000000000000LL;
        while (L < R) {
            long long mid = (L + R)/2;
            long long check = hours(piles,mid);
            if (check > hrs) { //need to go faster
                L = mid+1;
            }
            else if (check < hrs) { //can go slower, dont have to
                R = mid;
            }
            else { //perfect pace, check lower bound
                R = mid;
            }
        }
        return (int)(L);
    }
};