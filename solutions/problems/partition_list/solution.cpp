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
    int cnt(ListNode* head, int x) {
        if (head == nullptr) return 0;
        if (head->val >= x) return cnt(head->next,x);
        return 1 + cnt(head->next,x);
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode* cur = head;
        int lessThanX = cnt(cur,x);
        if (lessThanX == 0) return head;
        ListNode* newHead = new ListNode();
        cur = head;
        ListNode* newCur = newHead;
        while (cur != nullptr) {
            if (cur->val < x) {
                newCur->val = cur->val;
                newCur->next = new ListNode();
                newCur = newCur->next;
            }
            cur = cur->next;
        }
        cur = head;
        while (cur != nullptr) {
            if (cur->val >= x) {
                newCur->val = cur->val;
                newCur->next = new ListNode();
                newCur = newCur->next;
            }
            cur = cur->next;
        }
        newCur = newHead;
        if (newCur->next == nullptr) return nullptr;
        while (newCur->next->next != nullptr) newCur = newCur->next;
        if (newCur != nullptr) newCur->next = nullptr;
        return newHead;

    }
};