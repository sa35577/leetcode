class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n > 1) {
            if ((n/2) * 2 != n) return false;
            n >>= 1;
        }
        return true;
    }
};