typedef long long ll;
class Solution {
public:
    int numOfWays(int n) {
//         3 1 2
//         1 2 3 //ad
            
//         3 1 2
//         1 2 1
            
//         3 1 2
//         1 3 1
            
        
//         3 1 2
//         2 3 1 //ad
        
//         ----
        
//         1 2 1
//         2 1 2
        
//         1 2 1
//         2 1 3 //ad
        
//         1 2 1
//         2 3 2
        
//         1 2 1
//         3 1 2 //ad
        
//         1 2 1
//         3 1 3
        
        const ll mod = 1000000007LL;
        vector<ll> allDiff(n);
        allDiff[0] = 6;
        vector<ll> twoSame(n);
        twoSame[0] = 6;
        for (int i = 1; i < n; i++) {
            allDiff[i] = ((allDiff[i-1] * 2) % mod + (twoSame[i-1] * 2) % mod) % mod;
            twoSame[i] = ((allDiff[i-1] * 2) % mod + (twoSame[i-1] * 3) % mod) % mod;
        }
        return (int)((allDiff.back() + twoSame.back()) % mod);
            
        
    }
};