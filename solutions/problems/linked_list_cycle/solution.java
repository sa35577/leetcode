/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode n1 = head, n2 = head;
        if (head == null) return false;
        for (int i = 0; i < 20005; i++) {
            n1 = n1.next;
            n2 = n2.next;
            if (n1 == null || n2 == null) return false;
            n2 = n2.next;
            if (n2 == null) return false;
        }
        return true;
    }
}