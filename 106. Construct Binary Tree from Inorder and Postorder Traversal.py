# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not inorder and not postorder:
            return None

        divide = inorder.index(postorder[-1])
        root_node = TreeNode(inorder[divide])
        root_node.left = self.buildTree(inorder[ :divide], postorder[:divide])
        root_node.right = self.buildTree(inorder[divide+1:], postorder[divide:-1])
        return root_node

            