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
    TreeNode* sortedArrayToBST(vector<int>& nums, int L, int R) {
        if (R < L) return nullptr;
        TreeNode* t = new TreeNode(nums[(L+R)/2]);
        t->left = sortedArrayToBST(nums,L,(L+R)/2-1);
        t->right = sortedArrayToBST(nums,(L+R)/2+1,R);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
};