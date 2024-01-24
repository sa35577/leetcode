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
    int paths(TreeNode* root, map<int,int>& mp) {
        if (root == nullptr) return 0;
        mp[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            int odd = 0;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                if (it->second % 2 == 1) odd++;
            }
            mp[root->val]--;
            if (odd <= 1) return 1;
            return 0;
        }
        int x1 = paths(root->left,mp);
        int x2 = paths(root->right,mp);
        mp[root->val]--;
        return x1+x2;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> mp;
        for (int i = 1; i <= 9; i++) mp[i] = 0;
        return paths(root,mp);
    }
};