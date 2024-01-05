# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def valid(self,root: Optional[TreeNode],L: int, R: int) -> bool:
        if root == None:
            return True
        if root.val <= L or root.val >= R:
            return False
        return (self.valid(root.left,L,root.val) and self.valid(root.right,root.val,R))
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.valid(root,- (2**31 + 1), 2**31)