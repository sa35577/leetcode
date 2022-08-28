/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */

var arrGen = function(root) {
    let arr = [];
    if (root == null) return arr;
    let res1 = arrGen(root.left), res2 = arrGen (root.right);
    res1.push(root.val);
    for (let i = 0; i < res2.length; i++) {
        res1.push(res2[i]);
    }
    return res1;
}
var isValidBST = function(root) {
    let arr = arrGen(root);
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] <= arr[i-1]) return false;
    }
    return true;
};