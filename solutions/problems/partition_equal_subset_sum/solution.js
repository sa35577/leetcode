/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
    let sum = 0, dp = [1], ndp = [1];
    for (let i = 1; i <= 20001; i++) {
        dp.push(0);
        ndp.push(0);
    }
    let blankNdp = ndp;
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        ndp = blankNdp;
        for (let j = 20000; j >= 0; j--) {
            ndp[j] = dp[j];
            if (j >= nums[i] && dp[j - nums[i]] == 1) ndp[j] = 1;
        }
        dp = ndp;
    }
    if (sum % 2 == 1) return false;
    let half = Math.floor(sum / 2);
    if (dp[half] == 1) return true;
    return false;
};