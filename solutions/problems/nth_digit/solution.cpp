class Solution {
public:
    int findNthDigit(int n) {
        int numDigs = 1;
        while (true) {
            if ((pow(10,numDigs) - pow(10,numDigs-1)) * numDigs >= n) {
                break;
            }
            n -= (pow(10,numDigs) - pow(10,numDigs-1)) * numDigs;
            numDigs++;
        }
        n--;
        int x = (n / numDigs) + pow(10,numDigs-1);
        int dig = n % numDigs;
        string s = to_string(x);

        return s[dig]-'0';

    }
};