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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        vector<int> leftEnd = inorderTraversal(root->left), rightEnd = inorderTraversal(root->right);
        res.insert(res.end(),leftEnd.begin(),leftEnd.end());
        res.push_back(root->val);
        res.insert(res.end(),rightEnd.begin(),rightEnd.end());
        return res;
    }
};