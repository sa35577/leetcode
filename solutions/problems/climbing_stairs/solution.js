/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    let x = [1,1];
    for (let i = 2; i <= n; i++) {
        x.push(x[i-1]+x[i-2])
    }
    return x[n];
};