class Solution {
public:
    int bitwiseComplement(int n) {
        long long N = (long long)(n);
        long long powerOfTwo = 2;
        while (powerOfTwo <= N) {
            powerOfTwo = powerOfTwo * 2;
        }
        return (int)(powerOfTwo-1-N);
    }
};