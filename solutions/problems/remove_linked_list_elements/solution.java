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
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) return head;
        ListNode newNext;
        while (head != null && head.val == val) {
            newNext = head.next;
            head = null;
            head = newNext;
        }
        ListNode cur = head;
        while (cur != null) {
            while (cur.next != null && cur.next.val == val) {
                newNext = cur.next.next;
                cur.next = null;
                cur.next = newNext;
            }
            cur = cur.next;
        }
        return head;
    }
}