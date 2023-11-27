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
    vector<vector<int>> trav(TreeNode* root, vector<int> soFar) {
        vector<vector<int>> v;
        if (root == nullptr) return v;
        if (root->left == nullptr && root->right == nullptr) {
            soFar.push_back(root->val);
            v.push_back(soFar);
            return v;
        }
        soFar.push_back(root->val);
        vector<vector<int>> left = trav(root->left,soFar);
        vector<vector<int>> right = trav(root->right,soFar);
        v.insert(v.end(),left.begin(),left.end());
        v.insert(v.end(),right.begin(),right.end());
        return v;
              
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<vector<int>> paths = trav(root,{});
        vector<vector<int>> v;
        for (vector<int> path : paths) {
            reverse(path.begin(),path.end());
            v.push_back(path);
        }
        sort(v.begin(),v.end());
        string s = "";
        for (int x : v[0]) {
            s += (x + 'a');
        }
        return s;
    }
};