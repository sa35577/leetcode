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
    vector<long long> v;
    void setVal(TreeNode* root, int depth) {
        if (root == nullptr) return;
        v[depth] = max(v[depth],(long long)(root->val));
        setVal(root->left,depth+1);
        setVal(root->right,depth+1);
    }
    vector<int> largestValues(TreeNode* root) {
        v.resize(10005);
        for (int i = 0; i < 10005; i++) {
            v[i] = LLONG_MIN;
        }
        setVal(root,0);
        vector<int> vv;
        for (int i = 0; i < 10005; i++) {
            if (v[i] == LLONG_MIN) break;
            vv.push_back((int)(v[i]));
        }
        return vv;

    }
};