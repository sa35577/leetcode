class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = false;
        long long divident = dividend, divis = divisor;
        if (divident < 0 && divis > 0) {
            divident = -divident;
            neg = true;
        }
        else if (divident > 0 && divis < 0) {
            divis = -divis;
            neg = true;
        }
        else if (divident < 0 && divis < 0) {
            divident = -divident;
            divis = -divis;
        }
        if (divident == 0) return 0;
        long long arr[33],lst[33];
        arr[0] = divis;
        lst[0] = 1;
        for (int i = 1; i < 32; i++) arr[i] = arr[i-1] + arr[i-1];
        for (int i = 1; i < 32; i++) lst[i] = lst[i-1] + lst[i-1];
        if (divident >= arr[31] && neg) {
            return -arr[31];
        }
        else if (divident >= arr[31]-1 && !neg) {
            return arr[31]-1;
        }
        long long res = 0;
        for (int i = 31; i > -1; i--) {
            if (arr[i] <= divident) {
                divident -= arr[i];
                res += lst[i];
            }
        }
        if (neg) return -res;
        return res;
        
        
        
    }
};