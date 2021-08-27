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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode faster = head;
        if (head.next == null) {
            return null;
        }
        for (int i = 0; i < n; i++) faster = faster.next;
        if (faster == null) {
            head = head.next;
            return head;
        }
        ListNode slower = head;
        while (faster.next != null) {
            faster = faster.next;
            slower = slower.next;
        }
        if (slower.next.next == null) {
            slower.next = null;
            return head;
        }
        slower = slower.next;
        slower.val = slower.next.val;
        slower.next = slower.next.next;
        return head;
    }
}