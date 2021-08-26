#include <map>

class Solution {
public:
    map<int,int> f;
    
    
    int fib(int n) {
        if (n <= 0) return 0;
        if (n <= 2) return 1;
        if (f.find(n) != f.end()) return f[n];
        else return f[n] = fib(n-1) + fib(n-2);
    }
};