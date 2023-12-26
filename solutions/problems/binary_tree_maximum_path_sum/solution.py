# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    nodeCount = 0
    maxSumTouch = [-10000 for i in range(30005)]
    maxSumDown = [-10000 for i in range(30005)]


    def augment(self, root: Optional[TreeNode]) -> TreeNode:
        if root == None:
            return root
        root.val = [root.val,self.nodeCount]
        self.nodeCount += 1
        if root.left != None:
            root.left = self.augment(root.left)
        if root.right != None:
            root.right = self.augment(root.right)
        return root

    def maxsumdown(self,root):
        if root == None:
            return -100000000
        if self.maxSumDown[root.val[1]] > -10000:
            return self.maxSumDown[root.val[1]]
        curSum = root.val[0]
        leftSum,rightSum = 0,0

        if root.left != None:
            self.maxsumdown(root.left)
            leftSum = self.maxSumDown[root.left.val[1]]
        if root.right != None:
            self.maxsumdown(root.right)
            rightSum = self.maxSumDown[root.right.val[1]]
        
        self.maxSumDown[root.val[1]] = curSum + max(0,leftSum,rightSum)
        return self.maxSumDown[root.val[1]]

    def maxsumtouch(self,root):
        if root == None:
            return -100000000
        if self.maxSumTouch[root.val[1]] > -10000:
            return self.maxSumTouch[root.val[1]]
        curSum = root.val[0] + max(0,self.maxsumdown(root.left)) + max(0,self.maxsumdown(root.right))
        self.maxSumTouch[root.val[1]] = curSum
        return curSum
        
    def maxsum(self,root):
        if root.left != None:
            self.maxsum(root.left)
        if root.right != None:
            self.maxsum(root.right)
        self.maxsumtouch(root)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:

        self.nodeCount = 0
        self.maxSumTouch = [-10000 for i in range(30005)]
        self.maxSumDown = [-10000 for i in range(30005)]

        root = self.augment(root)
        self.maxsumdown(root)
        self.maxsum(root)
        # print(self.maxSumDown[0:6])
        # print(self.maxSumTouch[0:6])
        return max(self.maxSumTouch[0:self.nodeCount])


