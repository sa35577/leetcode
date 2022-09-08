/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool cons(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return (subRoot == nullptr);
        }
        if (subRoot == nullptr) return false;
        if (root->val != subRoot->val) return false;
        return (cons(root->left,subRoot->left) && cons(root->right,subRoot->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (cons(root,subRoot)) return true;
        if (root == nullptr || subRoot == nullptr) return false;
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};