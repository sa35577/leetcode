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
    ListNode* doubleIt(ListNode* head) {
        deque<int> q;
        ListNode* cur = head;
        q.push_back(head->val);
        while (cur->next != NULL) {
            cur = cur->next;
            q.push_back(cur->val);
        }
        deque<int> qq;
        int carry = 0;
        while (!q.empty()) {
            qq.push_front(carry+2 * q.back());
            if (carry + 2 * q.back() >= 10) {
                carry = 1;
                qq.front() -= 10;
            }
            else carry = 0;
            q.pop_back();
        }
        if (carry == 1) qq.push_front(1);
        ListNode *h1 = new ListNode{qq.back()};
        qq.pop_back();
        while (!qq.empty()) {
            ListNode* h = new ListNode{qq.back(),h1};
            h1 = h;
            qq.pop_back();
        }
        return h1;
    }
};