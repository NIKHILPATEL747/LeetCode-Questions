# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def levelOrder(self, root):
        if not root:
            return []
        
        result = []
        queue = [root]   # start with root in queue
        
        while queue:
            currlevel = []
            nextlevel = []
            
            for node in queue:
                currlevel.append(node.val)
                if node.left:
                    nextlevel.append(node.left)
                if node.right:
                    nextlevel.append(node.right)
            
            result.append(currlevel)
            queue = nextlevel   # move to next level
        
        return result
