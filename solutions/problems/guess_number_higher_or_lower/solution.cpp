/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int L = 1, R = n;
        while (L < R) {
            int mid = L + (R-L)/2;
            int res = guess(mid);
            if (res == 0) return mid;
            else if (res == -1) R = mid-1;
            else L = mid+1;
        }
        return L;
    }
};