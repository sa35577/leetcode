class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        long long x = 1, nn = (long long)n;
        while (x < nn) x *= 3;
        return (x == nn);
    }
};