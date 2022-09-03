class Solution {
public:
    bool isPerfectSquare(int num) {
        int L = 1, R = 46340;
        while (L < R) {
            int mid = (L+R)/2;
            if (mid * mid == num) return true;
            else if (mid * mid > num) R = mid-1;
            else L = mid+1;
        }
        return (L * L == num);
    }
};