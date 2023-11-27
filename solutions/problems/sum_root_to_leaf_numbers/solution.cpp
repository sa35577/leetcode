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
    int trav(TreeNode* root, int soFar) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) {
            return soFar*10 + root->val;
        }
        return trav(root->left,soFar*10+root->val) + trav(root->right,soFar*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        return trav(root,0);
    }
};