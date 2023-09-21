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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
        cout << preL << " " << preR << " " << inL << " " << inR << endl;
        TreeNode *t = new TreeNode;
        if (preL > preR) return nullptr;
        if (preL == preR) {
            t->val = preorder[preL];
            t->left = nullptr;
            t->right = nullptr;
            return t;
        }
        int idx = inL;
        while (inorder[idx] != preorder[preL]) idx++;
        int offset = idx-inL;
        t->val = preorder[preL];
        t->left = build(preorder,inorder,preL+1,preL+offset,inL,idx-1);
        t->right = build(preorder,inorder,preL+offset+1,preR,idx+1,inR);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};