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
    TreeNode* recTail(TreeNode* root, TreeNode* prev) {
        if (root == nullptr) return prev;
        if (prev != nullptr) prev->right = root;
        if (root->left == nullptr && root->right == nullptr) return root;
        if (root->left == nullptr) {
            return recTail(root->right,root);
        }
        else {
            TreeNode* after = root->right;
            TreeNode* res = recTail(root->left,root);
            root->left = nullptr;
            return recTail(after,res);
        }
        
    }
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        else if (root->left == nullptr && root->right == nullptr) return;
        recTail(root,nullptr);
    }
};