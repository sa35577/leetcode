// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long L = 1, R = n;
        while (L < R) {
            long long mid = (L+R)>>1;
            bool res = isBadVersion(mid);
            if (!res) L = mid+1;
            else R = mid;
        }
        return L;
    }
};