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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if (root == nullptr) {
            return v;
        }
        deque<TreeNode*> curLevel;
        deque<TreeNode*> nextLevel;
        v.push_back(root->val);
        curLevel.push_back(root);
        while (true) {
            while (!curLevel.empty()) {
                TreeNode *cur = curLevel.front();
                curLevel.pop_front();
                if (cur->right) nextLevel.push_back(cur->right);
                if (cur->left) nextLevel.push_back(cur->left);
            }
            if (nextLevel.empty()) break;
            v.push_back(nextLevel.front()->val);
            curLevel = nextLevel;
            nextLevel.clear();
        }
        return v;
    }
};