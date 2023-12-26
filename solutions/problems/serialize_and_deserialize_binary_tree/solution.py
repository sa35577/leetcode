# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root == None:
            return ""
        cnt = 1
        ret = [str(root.val)]
        curList = [root]
        while cnt > 0:
            nextList = []
            cnt = 0
            for node in curList:
                if node != None:
                    nextList.append(node.left)
                    nextList.append(node.right)
                    for newnode in [node.left, node.right]:
                        if newnode == None:
                            ret.append("null")
                        else:
                            ret.append(str(newnode.val))
                    cnt += 1
            curList = nextList

        return ",".join(ret)

    def nonnullcount(self,lst):
        cnt = 0
        for i in lst:
            if i != "null":
                cnt += 1
        return cnt

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == "":
            return None
        lst = data.split(",")
        curIdx = 1
        layers = [[int(lst[0])]]
        while curIdx < len(lst):
            curSize = self.nonnullcount(layers[-1])
            nextlayer = []
            for i in range(2*curSize):
                if lst[curIdx + i] == "null":
                    nextlayer.append("null")
                else:
                    nextlayer.append(int(lst[curIdx + i]))
            layers.append(nextlayer)
            curIdx += 2*curSize
        
        nodes = []
        for i in layers[-1]:
            if i == "null":
                nodes.append(None)
            else:
                nodes.append(TreeNode(i))
        for i in range(len(layers)-2,-1,-1):
            cnt = 0
            newnodes = []
            for j in range(len(layers[i])):
                if layers[i][j] == "null":
                    newnodes.append(None)
                else:
                    node = TreeNode(layers[i][j])
                    node.left = nodes[cnt]
                    node.right = nodes[cnt+1]
                    cnt += 2
                    newnodes.append(node)
            nodes = newnodes
        return nodes[0]

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))