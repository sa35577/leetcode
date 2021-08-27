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
    int maxDepth = -1;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<pair<int,int>> travVals = trav(root,0);
        vector<vector<int>> ans(maxDepth+1);
        int sz = 0;
        for (pair<int,int> p : travVals) {
            ans[p.second].push_back(p.first);
        }
        return ans;
    }
    vector<pair<int,int>> trav(TreeNode* root, int curDepth) {
        vector<pair<int,int>> v;
        if (root == NULL) return v;
        for (pair<int,int> p : trav(root->left,curDepth+1)) v.push_back(p);
        v.push_back({root->val,curDepth});
        for (pair<int,int> p : trav(root->right,curDepth+1)) v.push_back(p);
        maxDepth = max(maxDepth,curDepth);
        return v;
    }
};