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
    vector<int> vals;
    void addNodes (TreeNode* cur) {
        if (cur == NULL) return;
        addNodes(cur->left);
        vals.push_back(cur->val);
        addNodes(cur->right);
    }
    bool findTarget(TreeNode* root, int k) {
        addNodes(root);
        int L = 0, R = vals.size()-1;
        while (L < R) {
            if (vals[L]+vals[R] == k) return true;
            else if (vals[L]+vals[R] > k) {
                R--;
            }
            else {
                L++;
            }
        }
        return false;
        
    }
};