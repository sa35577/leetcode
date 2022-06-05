function combinationSum4(nums: number[], target: number): number {
    let dp = [];
    dp.push(1);
    for (let i = 1; i <= target; i++) {
        dp.push(0);
        nums.forEach((num) => {
            if (i - num >= 0) dp[i] += dp[i - num];
        })
    }
    return dp[target];
    
};