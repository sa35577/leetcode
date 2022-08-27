/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    let dct = {};
    
    while (n != 1) {
        dct[n] = 1;
        let sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n = Math.floor(n/10);
        }
        if (sum in dct) return false;
        n = sum;
    }
    return true;
};