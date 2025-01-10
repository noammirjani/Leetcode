# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import Optional


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def height(root) -> int:
            if not root:
                return 0

            left = height(root.left)
            right = height(root.right)
            if left == -1 or right == -1 or abs(left-right) > 1:
                return -1
            return max(left, right)+1
        return height(root) != -1
