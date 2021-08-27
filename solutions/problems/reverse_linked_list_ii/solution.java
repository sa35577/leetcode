/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head.next == null || left == right) return head;
        if (left > 1) {
            ListNode justBefore = head;
            int jbIdx = 1;
            while (jbIdx + 1 < left) {
                justBefore = justBefore.next;
                jbIdx++;
            }
            ListNode revTail = justBefore.next;
            int cnt = right-left;
            while (cnt > 0) {
                ListNode newHead = revTail.next;
                if (newHead.next == null) revTail.next = null; 
                else revTail.next = newHead.next;
                newHead.next = justBefore.next;
                justBefore.next = newHead;
                cnt--;
            }
        }
        else {
            ListNode revTail = head;
            int cnt = right-left;
            while (cnt > 0) {
                ListNode newHead = revTail.next;
                if (newHead.next == null) revTail.next = null; 
                else revTail.next = newHead.next;
                newHead.next = head;
                head = newHead;
                cnt--;
            }
        }
        return head;
    }
}