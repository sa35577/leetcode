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
    int goodNodes(TreeNode* root) {
        return trav(root,root->val);
    }
    int trav(TreeNode* root, int curMax) {
        if (root == NULL) return 0;
        if (curMax <= root->val) {
            return 1+trav(root->left,root->val)+trav(root->right,root->val);
        }
        return trav(root->left,curMax)+trav(root->right,curMax);
    }
};