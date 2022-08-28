/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */

var hasNode = function(root, n) {
    if (root == null) return false;
    if (root.val == n.val) return true;
    return (hasNode(root.left,n) || hasNode(root.right,n));
}
var lowestCommonAncestor = function(root, p, q) {
    if (root.val == p.val || root.val == q.val) return root;
    var b1 = hasNode(root.left,p), b2 = hasNode(root.left,q);
    if (b1 && b2) return lowestCommonAncestor(root.left,p,q);
    else if (!(b1 || b2)) return lowestCommonAncestor(root.right,p,q);
    return root;
};