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
    vector<int> getAllNodes(TreeNode* root) {
        vector<int> v;
        if (root == nullptr) return v;
        v.push_back(root->val);
        vector<int> left = getAllNodes(root->left), right = getAllNodes(root->right);
        v.insert(v.end(),left.begin(),left.end());
        v.insert(v.end(),right.begin(),right.end());
        return v;
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v = getAllNodes(root);
        sort(v.begin(),v.end());
        int mn = INT_MAX;
        for (int i = 1; i < v.size(); i++) mn = min(mn,v[i] - v[i-1]);
        return mn;
    }
};