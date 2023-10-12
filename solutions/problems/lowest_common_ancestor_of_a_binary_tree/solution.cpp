/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> ppath,qpath;

    bool findNode(TreeNode* root, TreeNode* v) {
        if (root == v) {
            ppath.push_back(root);
            return true;
        }
        if (root == nullptr) return false;
        bool b1 = findNode(root->left,v), b2 = findNode(root->right,v);
        if (b1 || b2) {
            ppath.push_back(root);
        }
        return (b1 || b2);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == q) return p;
        findNode(root,q);
        qpath = ppath;
        ppath.clear();
        findNode(root,p);
        reverse(qpath.begin(),qpath.end());
        reverse(ppath.begin(),ppath.end());
        for (int i = 0; i < min(qpath.size(),ppath.size()); i++) {
            if (qpath[i] != ppath[i]) return qpath[i-1];
        }
        if (qpath.size() < ppath.size()) return qpath.back();
        else if (qpath.size() > ppath.size()) return ppath.back();
        return nullptr;
    }
};