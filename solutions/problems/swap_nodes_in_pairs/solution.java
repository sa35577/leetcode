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
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode a = head, b = head.next,c = head;
        a.next = b.next;
        b.next = a;
        head = b;
        while (a.next != null && a.next.next != null) {
            b = a.next;
            c = a.next.next;
            b.next = c.next;
            c.next = b;
            a.next = c;
            a = b;
            
        }
        return head;
        
    }
}