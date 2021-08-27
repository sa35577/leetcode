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
    vector<int> collections(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        for (int i : collections(root->left)) res.push_back(i);
        res.push_back(root->val);
        for (int i : collections(root->right)) res.push_back(i);
        return res;
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> vals = collections(root);
        for (int i = 1; i < vals.size(); i++) if (vals[i] <= vals[i-1]) return false;
        return true;
    }
};