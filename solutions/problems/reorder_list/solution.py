# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if (head.next == None ) or (head.next.next == None):
            return
        listOfNodes = [head]
        cur = head
        while cur.next != None:
            cur = cur.next
            listOfNodes.append(cur)
        L,R = 0,len(listOfNodes)-1
        cnt = 0
        while L < R:
            if cnt == 0:
                listOfNodes[L].next = listOfNodes[R]
                L += 1
            elif cnt == 1:
                listOfNodes[R].next = listOfNodes[L]
                R -= 1
            cnt = 1 - cnt
        listOfNodes[L].next = None
        return