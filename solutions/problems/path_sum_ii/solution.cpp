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
    bool isLeaf(TreeNode* root) {
        if (root == nullptr) return false;
        return (root->left == nullptr && root->right == nullptr);
    }

    vector<vector<int>> pathSumRec(TreeNode* root, int targetSum, vector<int> soFar) {
        vector<vector<int>> res;
        if (!root) return res;
        if (isLeaf(root) && targetSum == root->val) {
            soFar.push_back(root->val);
            res.push_back(soFar);
            return res;
        }
        else if (isLeaf(root)) return res;
        
        soFar.push_back(root->val);
        vector<vector<int>> left = pathSumRec(root->left,targetSum-root->val,soFar);
        vector<vector<int>> right = pathSumRec(root->right,targetSum-root->val,soFar);
        res.insert(res.end(),left.begin(),left.end());
        res.insert(res.end(),right.begin(),right.end());
        return res;
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> soFar{};
        return pathSumRec(root,targetSum,soFar);
    }
};