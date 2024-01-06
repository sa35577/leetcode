/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rec(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == nullptr && l2 == nullptr) {
            if (carry == 1) return new ListNode(1);
            else return nullptr;
        }
        else if (l2 == nullptr) {
            int v = carry + l1->val;
            ListNode* node = new ListNode(v%10);
            if (v < 10) {
                node->next = l1->next;
            }
            else {
                node->next = rec(l1->next,nullptr,1);
            }
            return node;
        }
        else if (l1 == nullptr) {
            int v = carry + l2->val;
            ListNode* node = new ListNode(v%10);
            if (v < 10) {
                node->next = l2->next;
            }
            else {
                node->next = rec(nullptr,l2->next,1);
            }
            return node;
        }
        else {
            int v = carry + l1->val + l2->val;
            ListNode* node = new ListNode(v%10);
            if (v < 10) {
                node->next = rec(l1->next,l2->next,0);
            }
            else {
                node->next = rec(l1->next,l2->next,1);
            }
            return node;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return rec(l1,l2,0);
    }
};