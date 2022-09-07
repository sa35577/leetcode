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
    int removal(ListNode* cur, int n) {
        if (cur->next == nullptr) return 1;
        int res = removal(cur->next,n);
        if (res == n) {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        return 1 + res;
    }
    int getSize(ListNode* cur) {
        if (cur == nullptr) return 0;
        return 1 + getSize(cur->next);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (getSize(head) == n) return head->next;
        removal(head,n);
        return head;
    }
};