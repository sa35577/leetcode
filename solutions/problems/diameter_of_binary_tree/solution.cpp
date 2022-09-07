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
    int longestPath(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(longestPath(root->left),longestPath(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(longestPath(root->left) + longestPath(root->right), max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};