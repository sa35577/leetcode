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
    
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(),l3 = new ListNode(),l4 = new ListNode();
        boolean addNext = false,firstNode=true;
        while (l1 != null || l2 != null) {
            if (!firstNode) {
                l3.next = l4;
                l3 = l4;
            }
            if (l1 != null && l2 != null) {
                l3.val = l1.val+l2.val;
                if (addNext) {
                    addNext = false;
                    l3.val++;
                }
                if (l3.val >= 10) {
                    addNext = true;
                    l3.val %= 10;
                }
                l1 = l1.next;
                l2 = l2.next;
            }
            else {
                if (l1 == null) {l3.val = l2.val; l2 = l2.next; }
                else {l3.val = l1.val; l1 = l1.next;}
                if (addNext) {
                    addNext = false;
                    l3.val++;
                }
                if (l3.val >= 10) {
                    addNext = true;
                    l3.val %= 10;
                }
            }
            if (firstNode) {
                firstNode = false;
                head = l3;
            }
            l4 = new ListNode();
        }
        if (addNext) {
            l4 = new ListNode(1);
            l3.next = l4;
        }
        return head;
    }
}