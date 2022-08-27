/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    let freq = {};
    for (let i = 0; i < nums1.length; i++) {
        if (nums1[i] in freq) freq[nums1[i]]++;
        else freq[nums1[i]] = 1;
    }
    let intersection = [];
    for (let i = 0; i < nums2.length; i++) {
        if (nums2[i] in freq) {
            if (freq[nums2[i]] > 0) {
                intersection.push(nums2[i]);
                freq[nums2[i]]--;
            }
        }
    }
    return intersection;
};