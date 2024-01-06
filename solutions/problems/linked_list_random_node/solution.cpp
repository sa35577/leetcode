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
    int sz;
    ListNode* top;
    Solution(ListNode* head) {
        ListNode* cur = head;
        sz = 0;
        while (cur != nullptr) {
            cur = cur->next;
            sz++;
        }
        top = head;
    }
    
    int getRandom() {
        int idx = rand() % sz;
        ListNode* cur = top;
        while (idx > 0) {
            idx--;
            cur = cur->next;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */