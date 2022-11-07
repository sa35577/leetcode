class Solution {
public:
    int maximum69Number (int num) {
        int numCopy = num;
        int a = numCopy % 10;
        numCopy /= 10;
        int b = numCopy % 10;
        numCopy /= 10;
        int c = numCopy % 10;
        numCopy /= 10;
        int d = numCopy % 10;
        numCopy /= 10;
        if (d == 6) {
            d = 9;
        }
        else if (c == 6) {
            c = 9;
        }
        else if (b == 6) {
            b = 9;
        }
        else if (a == 6) {
            a = 9;
        }
        return 1000*d + 100*c + 10*b + a;
    }
};