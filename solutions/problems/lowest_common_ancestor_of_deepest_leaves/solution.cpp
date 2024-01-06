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
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(depth(root->left),depth(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return root;
        
        int d1 = depth(root->left), d2 = depth(root->right);
        if (d1 == d2) return root;
        else if (d1 > d2) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);
    }
};