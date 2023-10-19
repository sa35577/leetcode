class Solution {
public:
    int kthFactor(int n, int k) {
        int res = 0;
        int cur = 1;
        for (int i = 0; i < k; i++) {
            if (cur > n) return -1;
            while (n % cur != 0) cur++;
            cur++;
        }
        return cur-1;
    }
};