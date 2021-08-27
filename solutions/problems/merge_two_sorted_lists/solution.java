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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(), l3 = new ListNode();
        boolean firstNode = true;
        if (l1 == null && l2 == null) return null;
        while (l1 != null || l2 != null) {
            if (!firstNode) {
                l3.next = new ListNode();
                l3 = l3.next;
            }
            
            if (l1 != null && l2 != null) {
                if (l1.val <= l2.val) {
                    l3.val = l1.val;
                    l1 = l1.next;
                }
                else {
                    l3.val = l2.val;
                    l2 = l2.next;
                }
            }
            else {
                if (l1 == null) {
                    l3.val = l2.val;
                    l2 = l2.next;
                }
                else {
                    l3.val = l1.val;
                    l1 = l1.next;
                }
                
            }
            if (firstNode) {
                head = l3;
                firstNode = false;
            }
        }
        return head;
    }
}