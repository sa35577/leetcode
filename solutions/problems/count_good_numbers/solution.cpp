class Solution {
public:
    long long fastPow(long long base, int pow) {
        long long res = 1;
        if (pow == 0) return 1;
        while (pow > 0) {
            if (pow % 2 == 1) {
                res = (res * base) % 1000000007;
            }
            base = (base * base) % 1000000007;
            pow /= 2;
        }
        return (res) % 1000000007;
    }
    int countGoodNumbers(long long n) {
        long long oddCnt = n / 2, evenCnt = n - oddCnt;
        long long p = 1000000007;
        // cout << fastPow(5,0) << " " << fastPow(5,1) << " " << fastPow(5,2) << " " << fastPow(5,3) << " " << fastPow(5,4) << " " << fastPow(5,5) << " " << fastPow(5,6) << " " << fastPow(5,7);
        long long oddExp = oddCnt % (p-1), evenExp = evenCnt % (p-1);
        return (fastPow(5,evenExp) * fastPow(4,oddExp)) % 1000000007;

    }
};