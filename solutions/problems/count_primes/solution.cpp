class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        if (n <= 3) return 1;
        if (n <= 5) return 2;
        if (n <= 7) return 3;
        vector<int> primes{2,3,5,7};
        for (int test = 9; test < n; test += 2) {
            bool prime = true;
            for (int i : primes) {
                if (test % i == 0) {
                    prime = false;
                    break;
                }
                if (i*i >= test) break;
            }
            if (prime) primes.push_back(test);
        }
        return primes.size();
    }
};