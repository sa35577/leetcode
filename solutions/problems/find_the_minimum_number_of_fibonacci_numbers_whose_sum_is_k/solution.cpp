class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = {1,1};
        while (fib.back() < k) {
            fib.push_back(fib[fib.size()-2]+fib[fib.size()-1]);
        }
        int cnt = 0, idx = fib.size()-1;
        while (k > 0) {
            while (fib[idx] > k) idx--;
            k -= fib[idx];
            cnt++;
        }
        return cnt;
    }
};