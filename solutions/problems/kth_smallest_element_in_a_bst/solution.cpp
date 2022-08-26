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
    int size(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 1;
        res += size(root->left);
        res += size(root->right);
        return res;
    }
    int kthSmallest(TreeNode* root, int k) {
        int lsize = size(root->left);
        if (lsize >= k) return kthSmallest(root->left,k);
        else if (lsize+1 == k) return root->val;
        else return kthSmallest(root->right,k-lsize-1);
    }
};