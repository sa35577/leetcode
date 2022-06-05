/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    let leftProd = [nums[0]];
    let rightProd = [];
    for (let i = 0; i < nums.length; i++) {
        rightProd.push(0);
    }
    rightProd[nums.length-1] = nums[nums.length-1];
    for (let i = 1; i < nums.length; i++) {
        leftProd.push(leftProd[i-1] * nums[i]);
    }
    for (let i = nums.length - 2; i >= 0; i--) {
        rightProd[i] = rightProd[i+1] * nums[i];
    }
    console.log(leftProd);
    console.log(rightProd)
    let resProd = [rightProd[1]];
    for (let i = 1; i < nums.length - 1; i++) {
        resProd.push(leftProd[i-1] * rightProd[i+1]);
    }
    resProd.push(leftProd[nums.length - 2]);
    
    return resProd;
};