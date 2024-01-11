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
    int bestDiff(TreeNode* root, int mn, int mx) {
        if (root == nullptr) return INT_MIN;
        int soFar = max(abs(mn-root->val),abs(mx - root->val));
        soFar = max(soFar,bestDiff(root->left,min(mn,root->val),max(mx,root->val)));
        soFar = max(soFar,bestDiff(root->right,min(mn,root->val),max(mx,root->val)));
        return soFar;
    }
    int maxAncestorDiff(TreeNode* root) {
        return max(bestDiff(root->left,root->val,root->val),bestDiff(root->right,root->val,root->val));
    }
};