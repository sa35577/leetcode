class Solution {
public:
    int mySqrt(int x) {
        long long res = (long long)x;
        long long L = 0, R = (1<<16);
        while (L <= R) {
            long long mid = (L+R)/2;
            if (mid*mid == res) return (int)mid;
            else if (mid*mid > res) R = mid-1;
            else if ((mid+1)*(mid+1) > res) return (int)mid;
            else L = mid+1;
        }
        return -1;
    }
};