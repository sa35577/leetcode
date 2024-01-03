class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == INT_MIN) return false;
        int cpy = x;
        long long rev = 0;
        while (cpy > 0) {
            rev = rev * 10LL + (cpy%10);
            cpy = cpy/10;
        }
        return rev == (long long)(x);
    }
};