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
    bool isPalindrome(ListNode* head) {
        string s = "";
        while (head != NULL) {
            s += to_string(head->val);
            head = head->next;
        }
        int L = 0, R = s.size()-1;
        while (L < R) {
            if (s[L] != s[R]) return false;
            L++;R--;
        }
        return true;
    }
};