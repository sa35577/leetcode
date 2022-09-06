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
    ListNode* rec(ListNode* head, ListNode* cur) {
        if (cur == nullptr) return head;
        if (cur->val == 0) {
            head->next = rec(cur->next,cur->next);
            return head;
        }
        if (head != cur) head->val += cur->val;
        return rec(head,cur->next);
    }
    ListNode* mergeNodes(ListNode* head) {
        return rec(head->next,head->next);
    }
};