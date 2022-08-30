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
        if (head == nullptr || head->next == nullptr) return head;
        int cnt = 0;
        while (head->next != nullptr && head->val == head->next->val) {
            ListNode *tmp = head->next;
            head->next = head->next->next;
            delete tmp;
            cnt++;
        }
        if (cnt == 0) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        else {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
            return deleteDuplicates(head);
        }
        return nullptr;
    }
};