'''
File: 1038.py
File Created: 2021-01-12 13:43:24 -08:00
Author: Taowyoo (caoyxsh@outlook.com)
Brief: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/ 
-----
Last Modified: 2021-01-12 13:43:57 -08:00
Modified By: Taowyoo (caoyxsh@outlook.com>)
-----
Copyright 2020 - 2021
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    """Postorder Solution
    """
    last = 0
    def postOrder(self, root: TreeNode):
        if root is None:
            return
        self.postOrder(root.right)
        root.val += self.last
        self.last = root.val
        self.postOrder(root.left)

    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.postOrder(root)
        return root