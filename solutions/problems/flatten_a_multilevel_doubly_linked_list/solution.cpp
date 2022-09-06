/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatTail(Node* root, Node* prev) {
        if (root == nullptr) return prev;
        if (prev != nullptr) prev->next = root;
        root->prev = prev;
        if (root->child == nullptr) {
            return flatTail(root->next,root);
        }
        else {
            Node *after = root->next;
            root->next = root->child;
            root->child = nullptr;
            return flatTail(after,flatTail(root->next,root));
        }
    }
    Node* flatten(Node* head) {
        flatTail(head,nullptr);
        return head;
    }
};