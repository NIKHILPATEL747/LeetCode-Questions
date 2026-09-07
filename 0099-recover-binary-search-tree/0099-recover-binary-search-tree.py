# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        first = sec = prev = None
        curr = root

        while curr:
            if curr.left is None:
                # Check violation
                if prev and prev.val > curr.val:
                    if first is None:
                        first = prev
                    sec = curr
                prev = curr
                curr = curr.right
            else:
                # Find predecessor
                pred = curr.left
                while pred.right and pred.right != curr:
                    pred = pred.right

                if pred.right is None:
                    pred.right = curr
                    curr = curr.left
                else:
                    pred.right = None
                    if prev and prev.val > curr.val:
                        if first is None:
                            first = prev
                        sec = curr
                    prev = curr
                    curr = curr.right

        # Swap the two wrong nodes
        if first and sec:
            first.val, sec.val = sec.val, first.val
