class Solution {
public:
    double myPow(double x, int n) {
        long long nn = (long long)n;
        if (x == 1 || n == 0) return 1.0;
        double res = 1;
        if (nn > 0) {
            while (nn > 0) {
                if (nn%2==1) res *= x, nn--;
                if (nn > 0) x *= x, nn>>=1;
            }
        }
        else {
            nn = -nn;
            while (nn > 0) {
                if (nn%2==1) res /= x, nn--;
                if (nn > 0) x *= x, nn>>=1;
            }
        }
        return res;
        
    }
};