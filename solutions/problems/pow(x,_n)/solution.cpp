class Solution {
public:
    double myPow(double x, long long n) {
        double res = 1;
        if (n < 0) x = 1/x, n = -n;
        while (n > 0) {
            if (n % 2 == 1) res *= x;
            x *= x;
            n /= 2;
        }
        return res;
    }
    
    
};