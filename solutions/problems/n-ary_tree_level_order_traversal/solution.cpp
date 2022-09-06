/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> v;
    int trav(Node *root, int idx) {
        //ut << root->val << " " << idx << "\n";
        if (root == nullptr) return idx;
        v[idx].push_back(root->val);
        int res = idx+1;
        for (int i = 0; i < (root->children).size(); i++) {
            int r2 = trav(root->children[i],idx+1);
            cout << r2 << "aaaa\n";
            res = max(res,r2);
        }
        return res;
    } 
    vector<vector<int>> levelOrder(Node* root) {
        v.resize(10000);
        int level = trav(root,0);
        //ut << level << " ";
        for (int i = level; i < 10000; i++) {
            v.pop_back();
        }
        return v;
        
    }
};