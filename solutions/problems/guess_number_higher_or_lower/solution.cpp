/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long L = 1, R = n;
        while (L <= R) {
            long long mid = (L+R)/2;
            int res = guess(mid);
            if (res == 0) return mid;
            else if (res == 1) L = mid+1;
            else R = mid-1;
        }
        return -1;
    }
};