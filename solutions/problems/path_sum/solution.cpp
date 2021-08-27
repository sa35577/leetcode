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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(root,0,targetSum);
    }
    bool pathSum(TreeNode* root, int soFar, int target) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL) {
            if (soFar+root->val == target) return true;
            return false;
        }
        return (pathSum(root->left,soFar+root->val,target) || pathSum(root->right,soFar+root->val,target)); 
    }
};