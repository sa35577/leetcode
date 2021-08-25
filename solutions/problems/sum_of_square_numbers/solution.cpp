class Solution {
public:
    bool judgeSquareSum(int c) {
        long long C = (long long)c;
        for (long long i = 0; i < (1<<16); i++) {
            if (i*i>C) break;
            long long x = (long long)(sqrt(C-i*i));
            if (x*x==C-i*i) return true;
        }
        return false;
    }
};