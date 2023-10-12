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
    vector<int> getElements(ListNode* head) {
        if (head == nullptr) return {};
        vector<int> v = getElements(head->next);
        v.push_back(head->val);
        return v;
    }
    ListNode* sortList(ListNode* head) {
        vector<int> v = getElements(head);
        sort(v.begin(),v.end());
        ListNode* headCopy = head;
        for (int x : v) {
            headCopy->val = x;
            headCopy = headCopy->next;
        }
        return head;
    }
};