from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def is_valis_bst(self, root: Optional[TreeNode]) -> bool:
        def check(root, low, high):
            if not root:
                return True

            if low and low.val >= root.val or high and high.val <= root.val:
                return False

            # left and right
            return check(root.left, low ,root) and check(root.right, root, high)
        return check(root, None, None)


if __name__ == "__main__":
    s = Solution()
    tree = TreeNode(2, TreeNode(1), TreeNode(3))
    print(s.is_valis_bst(tree))  # True
    tree = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
    print(s.is_valis_bst(tree))  # False
    tree = TreeNode(5, TreeNode(4), TreeNode(6, TreeNode(3), TreeNode(7)))
    print(s.is_valis_bst(tree))  # False
    tree = TreeNode(5, TreeNode(4), TreeNode(6, TreeNode(8, TreeNode(3), TreeNode(7))))
    print(s.is_valis_bst(tree))  # False
