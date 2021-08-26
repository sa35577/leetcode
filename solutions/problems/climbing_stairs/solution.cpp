#include <map>

class Solution {
public:
    map<int,int> f;
    
    int climbStairs(int n) {
        if (n < 2) return 1;
        if (f.find(n) != f.end()) return f[n];
        else return f[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};