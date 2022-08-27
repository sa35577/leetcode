/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    let window = {};
    for (let i = 0; i <= Math.min(k,nums.length - 1); i++) {
        if (nums[i] in window) window[nums[i]]++;
        else window[nums[i]] = 1;
        if (window[nums[i]] >= 2) return true;
    }
    for (let i = k+1; i < nums.length; i++) {
        window[nums[i-(k+1)]]--;
        if (window[nums[i-(k+1)]] == 0) delete window[nums[i-(k+1)]];
        if (nums[i] in window) window[nums[i]]++;
        else window[nums[i]] = 1;
        if (window[nums[i]] >= 2) return true;
    }
    return false;
    
};