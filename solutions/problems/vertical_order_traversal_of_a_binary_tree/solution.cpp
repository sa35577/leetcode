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
    map<int,vector<pair<int,int>>> mp;
    void trav(TreeNode *root, int y, int x) {
        if (root == nullptr) return;
        if (mp.find(x) == mp.end()) {
            vector<pair<int,int>> v;
            mp[x] = v;
        }
        mp[x].push_back({y,root->val});
        trav(root->left,y+1,x-1);
        trav(root->right,y+1,x+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        trav(root,0,0);
        vector<vector<int>> res;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<pair<int,int>> v = it->second;
            sort(v.begin(),v.end());
            vector<int> w;
            for (pair<int,int> p : v) {
                w.push_back(p.second);
            }
            res.push_back(w);
        }
        return res;
    }
};