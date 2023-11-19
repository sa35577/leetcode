class Solution {
public:

    int cnt(int x) {
        if (x == 1) return 10;
        int res = cnt(x-1);
        vector<int> v{9,9,8,7,6,5,4,3,2,1};
        int cur = 1;
        for (int i = 0; i < x; i++) cur *= v[i];
        return cur + res;
    }

    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        return cnt(n);
    }
};