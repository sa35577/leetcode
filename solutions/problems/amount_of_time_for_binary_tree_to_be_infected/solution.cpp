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
    unordered_map<TreeNode*,int> depth;
    vector<TreeNode*> path;
    int getDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (depth.find(root) != depth.end()) return depth[root];
        depth[root] = 1 + max(getDepth(root->left),getDepth(root->right));
        return depth[root];
    }
    bool getToValue(TreeNode* root, int val) {
        if (root == nullptr) return false;
        if (root->val == val) {
            path.push_back(root);
            return true;
        }
        if (getToValue(root->left,val) || getToValue(root->right,val)) {
            path.push_back(root);
            return true;
        }
        return false;
    }
    int amountOfTime(TreeNode* root, int start) {
        getDepth(root); //gets depth for all nodes
        getToValue(root,start);
        int mx = getDepth(path[0])-1;
        for (TreeNode* t : path) {
            cout << t->val << " " << getDepth(t) << endl;
        }
        for (int i = 1; i < path.size(); i++) {
            if (path[i]->left != nullptr && path[i]->left == path[i-1]) {
                mx = max(mx,i+getDepth(path[i]->right));
            }
            else {
                mx = max(mx,i+getDepth(path[i]->left));
            }
        }
        return mx;
    }
};