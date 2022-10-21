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
    int listSize(ListNode* head) {
        if (head == nullptr) return 0;
        return 1 + listSize(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int sz = listSize(head);
        if (head == nullptr || k == 0 || k % sz == 0) return head;
        k = k % sz;
        ListNode* tail = head;
        while (tail->next != nullptr) tail = tail->next;
        if (sz == 2 && k == 1) {
            tail->next = head;
            head->next = nullptr;
            return tail;
        }
        int newHeadIndex = sz-k;
        int curIndex = 0;
        ListNode* newHead;
        ListNode* newTail = head;
        while (curIndex + 1 != newHeadIndex) {
            curIndex++;
            newTail = newTail->next;
        }
        newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        return newHead;
    }
};