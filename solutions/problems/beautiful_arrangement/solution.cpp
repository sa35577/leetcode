class Solution {
public:

    bool used[30];
    int rec(int idx, int n) {
        if (idx == n+1) return 1;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i] && (idx % i == 0 || i % idx == 0)) {
                used[i] = 1;
                sum += rec(idx+1,n);
                used[i] = 0;
            }
        }
        return sum;
    }

    int countArrangement(int n) {
        for (int i = 0; i < 30; i++) used[i] = false;   
        return rec(1,n);
    }
};