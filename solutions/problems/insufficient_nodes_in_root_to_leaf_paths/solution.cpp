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
    // pair<TreeNode*, vector<int>> rec(TreeNode* root, int limit) {
    //     vector<int> v;
    //     if (root == nullptr) return make_pair(nullptr,v);
    //     if (root->left == nullptr && root->right == nullptr) {
    //         v.push_back(root->val);
    //         if (root->val < limit) return make_pair(nullptr,v);
    //         else return make_pair(root,v);
    //     }
    //     pair<TreeNode*, vector<int>> leftRec = rec(root->left,limit), rightRec = rec(root->right,limit);
    //     for (int x : leftRec.second) {
    //         v.push_back(x + root->val);
    //     }
    //     for (int x : rightRec.second) {
    //         v.push_back(x + root->val);
    //     }
    //     bool allLT = true;
    //     for (int x : v) {
    //         if (x >= limit) {
    //             allLT = false;
    //             break;
    //         }
    //     }
    //     if (allLT) return make_pair(nullptr, v);
    //     root->left = leftRec.first;
    //     root->right = rightRec.first;
    //     return make_pair(root,v);
    // }
    pair<TreeNode*, int> rec(TreeNode* root, int limit, int sum) {
        if (root == nullptr) return make_pair(nullptr,-1e9);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val + sum < limit) return make_pair(nullptr,root->val + sum);
            else return make_pair(root,root->val + sum);
        }
        pair<TreeNode*, int> leftRec = rec(root->left,limit,sum + root->val), rightRec = rec(root->right,limit,sum + root->val);
        root->left = leftRec.first;
        root->right = rightRec.first;
        if (max(leftRec.second, rightRec.second) < limit) {
            return make_pair(nullptr,max(leftRec.second, rightRec.second));
        }
        return make_pair(root,max(leftRec.second, rightRec.second));
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return rec(root,limit,0).first;
    }
};