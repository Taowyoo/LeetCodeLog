'''
File: 110.py
File Created: 2021-01-12 13:48:32 -08:00
Author: Taowyoo (caoyxsh@outlook.com)
Brief: https://leetcode.com/problems/balanced-binary-tree/
-----
Last Modified: 2021-01-12 13:48:41 -08:00
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
    """Recursive Solution

    """
    def isBalanced(self, root):

        def check(root):
            if root is None:
                return 0
            left  = check(root.left)
            if left == -1:
                return -1
            right = check(root.right)
            # if imbalanced return -1
            if right == -1 or abs(left - right) > 1:
                return -1
            return 1 + max(left, right)  # return current node height
            
        return check(root) != -1


class Solution(object):
    """Itrative Solution

    Args:
        object ([type]): [description]
    """
    def isBalanced(self, root):
        stack, node, last, depths = [], root, None, {}
        while stack or node:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack[-1]
                if not node.right or last == node.right:
                    node = stack.pop()
                    left, right  = depths.get(node.left, 0), depths.get(node.right, 0)
                    if abs(left - right) > 1: return False
                    depths[node] = 1 + max(left, right)
                    last = node
                    node = None
                else:
                    node = node.right
        return True