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
    bool needPrune(TreeNode* root, TreeNode* head) {
        if (root == nullptr) return true;
        if (root->val == 0 && (root->left == nullptr && root->right == nullptr)) return true;
        bool l = needPrune(root->left,root), r = needPrune(root->right,root);
        if (l) root->left = nullptr;
        if (r) root->right = nullptr;
        if (l && r) {
            if (root->val == 0) {
                root = nullptr;
                return true;
            }
            return false;
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool b = needPrune(root,nullptr);
        if (b) return nullptr;
        return root;
    }
};