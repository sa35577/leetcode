/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let ind1 = 0, ind2 = 0;
    while (ind1 < m || ind2 < n) {
        if (ind1 == m) {
            nums1[ind1+ind2] = nums2[ind2++];
        }
        else if (ind2 == n) {
            ind1++;
        }
        else {
            if (nums1[ind1+ind2] <= nums2[ind2]) {
                ind1++;
            }
            else {
                for (let i = m+n-1; i > ind1 + ind2; i--) {
                    nums1[i] = nums1[i-1];
                }
                nums1[ind1+ind2] = nums2[ind2++];
            }
        }
        console.log(ind1,ind2);
    }
    return;
};