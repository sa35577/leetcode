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
    vector<int> getLeafs(TreeNode* root) {
        if (root == nullptr) return {};
        if (root->left == nullptr && root->right == nullptr) return {root->val};
        vector<int> left = getLeafs(root->left), right = getLeafs(root->right);
        left.insert(left.end(),right.begin(),right.end());
        return left;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1 = getLeafs(root1), r2 = getLeafs(root2);
        if (r1.size() != r2.size()) return false;
        for (int i = 0; i < r1.size(); i++) {
            if (r1[i] != r2[i]) return false;
        }
        return true;
    }
};