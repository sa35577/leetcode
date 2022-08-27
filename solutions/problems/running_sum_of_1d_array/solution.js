/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    let sumArray = [nums[0]];
    for (let i = 1; i < nums.length; i++) {
        sumArray.push(sumArray[i-1] + nums[i]);
    }
    return sumArray;
};