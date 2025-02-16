# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor1(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        def isFather(root) -> bool:
            nonlocal fatherRoot
            if not root:
                return False
            left = isFather(root.left)
            right = isFather(root.right)
            rootIsTarget = root == p or root == q
            if (left and right) or (rootIsTarget and (left or right)):
                fatherRoot = root
                return True
            return rootIsTarget or left or right

        fatherRoot = None
        isFather(root)
        return fatherRoot

    def lowestCommonAncestor2(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        if not root:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        rootIsTarget = root == p or root == q
        if (left and right) or (rootIsTarget and (left or right)):
            return root
        return root if rootIsTarget else left or right

    def lowestCommonAncestor3(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        if not root or root == p or root == q:
            return root

        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        if left and right:
            return root
        return left or right
