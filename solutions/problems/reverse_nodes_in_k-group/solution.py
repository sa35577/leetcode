# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    newHead = None
    def reverseK(self,cnt,cur,nxt):
        if cnt == 1:
            nxt.next = cur
            self.newHead = nxt
            return cur
        else:
            reorder = self.reverseK(cnt-1,nxt,nxt.next)
            reorder.next = cur
            return cur


    def reverseKGroupHelper(self, head: Optional[ListNode], k: int, n: int) -> Optional[ListNode]:
        # print(k,n)
        if k > n:
            return head
        cur = head
        for i in range(k-1):
            cur = cur.next
        cur.next = self.reverseKGroupHelper(cur.next,k,n-k)
        afterGroup = cur.next
        self.reverseK(k-1,head,head.next)
        head.next = afterGroup
        nHead = self.newHead
        return nHead

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k == 1:
            return head
        cur = head
        sz = 0
        while cur != None:
            cur = cur.next
            sz += 1
        return self.reverseKGroupHelper(head,k,sz)