/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* vis[102];

    Node* cloner(Node* node) {
        if (!node) return nullptr;
        if (vis[node->val]) return vis[node->val];
        Node* n = new Node(node->val);
        vis[node->val] = n;
        for (Node *nxt : node->neighbors) {
            vis[(node->val)]->neighbors.push_back(cloner(nxt));
        }
        return vis[node->val];
    }

    Node* cloneGraph(Node* node) {
        for (int i = 0; i < 102; i++) vis[i] = nullptr;
        return cloner(node);

    }
};