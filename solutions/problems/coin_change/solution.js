/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    let dp = new Array(amount+1).fill(100000);
    //console.log(dp);
    dp[0] = 0;
    for (let i = 1; i <= amount; i++) {
        coins.forEach((val) => {
            if (i - val >= 0) {
                dp[i] = Math.min(1+dp[i - val],dp[i]);
            }
        })
    }
    
    if (dp[amount] == 100000) return -1;
    return dp[amount];
};