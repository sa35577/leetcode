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
    deque<string> startDir,endDir;
    bool fnd(TreeNode* root, int target, bool start) {
        if (root == nullptr) return false;
        if (root->val == target) return true;
        if (fnd(root->left,target,start)) {
            if (start) startDir.push_back("L");
            else endDir.push_back("L");
            return true;
        }
        else if (fnd(root->right,target,start)) {
            if (start) startDir.push_back("R");
            else endDir.push_back("R");
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        fnd(root,startValue,true);
        fnd(root,destValue,false);
        while (!startDir.empty() && !endDir.empty() && startDir.back() == endDir.back()) {
            startDir.pop_back();
            endDir.pop_back();
        }
        string ret = "";
        while (!startDir.empty()) {
            ret += "U";
            startDir.pop_front();
        }
        while (!endDir.empty()) {
            ret += endDir.back();
            endDir.pop_back();
        }
        return ret;
    }
};