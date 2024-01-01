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
    vector<TreeNode*> v;
    int numNodes;
    map<TreeNode*,int> trans;
    int noInc[10004];
    int inc[10004];
    
    int rob(TreeNode* root) {
        deque<TreeNode*> deck;
        deck.push_back(root);
        numNodes = 0;
        while (!deck.empty()) {
            TreeNode* cur = deck.front();
            deck.pop_front();
            v.push_back(cur);
            trans[cur] = numNodes++;
            if (cur->left != nullptr) deck.push_back(cur->left);
            if (cur->right != nullptr) deck.push_back(cur->right);
        }
        memset(inc,0,sizeof(inc));
        memset(noInc,0,sizeof(noInc));
        for (int i = numNodes-1; i >= 0; i--) {
            TreeNode* cur = v[i];
            if (cur->left == nullptr && cur->right == nullptr) {
                noInc[i] = 0;
                inc[i] = cur->val;
            }
            else {
                //noinc
                int leftinc = 0, rightinc = 0;
                if (cur->left != nullptr) leftinc = inc[trans[cur->left]];
                if (cur->right != nullptr) rightinc = inc[trans[cur->right]];
                noInc[i] = leftinc + rightinc;
                //inc
                int leftnoinc = 0, rightnoinc = 0;
                if (cur->left != nullptr) leftnoinc = noInc[trans[cur->left]];
                if (cur->right != nullptr) rightnoinc = noInc[trans[cur->right]];
                inc[i] = max(noInc[i],cur->val + leftnoinc + rightnoinc);
            }
        }
        return inc[0];
    }
};