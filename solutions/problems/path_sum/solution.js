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
 * @param {number} targetSum
 * @return {boolean}
 */

var isLeaf = function(root) {
    return (root.left == null && root.right == null)
}

var pathRec = function(root, targetSum, soFar) {
    if (root == null) return false;
    if (isLeaf(root)) return (soFar + root.val == targetSum);
    return (pathRec(root.left,targetSum,soFar+root.val) || pathRec(root.right,targetSum,soFar+root.val));
    
}
var hasPathSum = function(root, targetSum) {
    return pathRec(root,targetSum,0);
};