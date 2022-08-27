/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
    let psa = [nums[0]];
    for (let i = 1; i < nums.length; i++) {
        psa.push(psa[i-1] + nums[i]);
    }
    let sum = psa[nums.length - 1];
    if (sum == nums[0]) return 0;
    for (let i = 1; i < nums.length - 1; i++) {
        if (psa[i-1] * 2 == sum - nums[i]) return i;
    }
    if (sum == nums[nums.length - 1]) return nums.length - 1;
    return -1;
    
};