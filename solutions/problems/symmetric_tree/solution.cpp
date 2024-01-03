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
    vector<int> travLeft(TreeNode* root) {
        if (root == nullptr) return {-1000};
        vector<int> v{root->val};
        vector<int> leftRec = travLeft(root->left), rightRec = travLeft(root->right);
        v.insert(v.end(),leftRec.begin(),leftRec.end());
        v.insert(v.end(),rightRec.begin(),rightRec.end());
        return v;
    }

    vector<int> travRight(TreeNode* root) {
        if (root == nullptr) return {-1000};
        vector<int> v{root->val};
        vector<int> leftRec = travRight(root->left), rightRec = travRight(root->right);
        v.insert(v.end(),rightRec.begin(),rightRec.end());
        v.insert(v.end(),leftRec.begin(),leftRec.end());
        return v;
    }



    bool isSymmetric(TreeNode* root) {
        vector<int> v1 = travLeft(root), v2 = travRight(root);
        if (v1.size() != v2.size()) return false;
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
};