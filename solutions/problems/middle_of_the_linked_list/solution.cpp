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
    ListNode* middleNode(ListNode* head) {
        ListNode* cur = head;
        int cnt = 0;
        while (cur != nullptr) {
            cur = cur->next;
            cnt++;
        }
        cnt /= 2;
        cur = head;
        while (cnt > 0) {
            cur = cur->next;
            cnt--;
        }
        return cur;
    }
};