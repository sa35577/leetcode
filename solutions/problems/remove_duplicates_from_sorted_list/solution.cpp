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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        while (head->next != nullptr && head->val == head->next->val) {
            ListNode* newNxt = head->next->next;
            delete head->next;
            head->next = newNxt;
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};