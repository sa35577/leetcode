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
 * @param {number} k
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
};

var findTarget = function(root, k) {
    let arr = arrGen(root);
    for (let i = 0; i < arr.length; i++) {
        arr[i] = arr[i] - k/2;
        if (arr[i] < 0) arr[i] = -arr[i];
    }
    //console.log(arr);
    arr.sort();
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] == arr[i-1]) return true;
    }
    return false;
    
};