# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        def dfs(root: TreeNode, target_1: TreeNode, target_2: TreeNode):
            if root is None:
                return None
            if target_1.val < root.val and target_2.val < root.val:
                return dfs(root.left, target_1, target_2)
            elif target_1.val > root.val and target_2.val > root.val:
                return dfs(root.right, target_1, target_2)
            else:
                return root
        
        return dfs(root, p, q)
