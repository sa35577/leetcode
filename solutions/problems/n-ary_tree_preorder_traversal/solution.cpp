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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == nullptr) return res;
        res.push_back(root->val);
        for (Node* nxt : root->children) {
            vector<int> rec = preorder(nxt);
            res.insert(res.end(),rec.begin(),rec.end());
        }
        return res;
    }
};