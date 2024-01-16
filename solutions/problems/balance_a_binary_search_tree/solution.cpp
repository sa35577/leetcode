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
    vector<int> v;
    void extractBST(TreeNode* root) {
        if (root == nullptr) return;
        extractBST(root->left);
        v.push_back(root->val);
        extractBST(root->right);
    }
    TreeNode* generateBST(int L, int R) {
        if (L > R) return nullptr;
        if (L == R) {
            return new TreeNode(v[L]);
        }
        return new TreeNode(v[(L+R)/2],generateBST(L,(L+R)/2-1),generateBST((L+R)/2+1,R));
    }
    TreeNode* balanceBST(TreeNode* root) {
        extractBST(root);
        return generateBST(0,v.size()-1);
    }
};