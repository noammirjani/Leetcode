from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self):
        return f"({self.val})"


def zigzag_level_order_2(root: Optional[TreeNode]) -> List[List[int]]:
    level_dict = {}  # {level: [nodes]}

    def dfs(node, level):
        if not node:
            return
        level_dict.setdefault(level, []).append(node.val)
        dfs(node.left, level + 1)
        dfs(node.right, level + 1)

    dfs(root, 0)
    res = []
    index = 0
    while index in level_dict:
        res.append(level_dict[index] if index % 2 == 0 else level_dict[index][::-1])
        index += 1
    return res


def zigzag_level_order(root: Optional[TreeNode]) -> List[List[int]]:
    res = []

    def dfs(node, level):
        if not node:
            return
        if len(res) == level:
            res.append([])

        if level % 2 == 0:
            res[level].append(node.val)
        else:
            res[level].insert(0, node.val)

        dfs(node.left, level + 1)
        dfs(node.right, level + 1)

    dfs(root, 0)
    return res


if __name__ == "__main__":
    tree = TreeNode(1, TreeNode(2, TreeNode(3), TreeNode(4)), TreeNode(5, TreeNode(6), TreeNode(7)))
    new_tree = zigzag_level_order(tree)
    print( new_tree)  # [[1], [5, 2], [3, 4, 6, 7]]


