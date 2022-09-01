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
    int goodNotes(TreeNode* root, int curMax) {
        if (root == nullptr) return 0;
        int x;
        if (root->val >= curMax) {
            x = 1;
        }
        else {
            x = 0;
        }
        x += goodNotes(root->left,max(curMax,root->val));
        x += goodNotes(root->right,max(curMax,root->val));
        return x;
    }
    int goodNodes(TreeNode* root) {
        return goodNotes(root,-100000);
    }
};