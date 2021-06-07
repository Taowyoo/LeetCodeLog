'''
File: 2.py
File Created: 2021-01-04 20:49:38 -08:00
Author: Taowyoo (caoyxsh@outlook.com)
Brief: https://leetcode.com/problems/add-two-numbers/solution/
-----
Last Modified: 2021-01-04 21:06:26 -08:00
Modified By: Taowyoo (caoyxsh@outlook.com>)
-----
Copyright 2020 - 2021
'''

class Solution:
def addTwoNumbers(self, l1, l2):
    """ Add two number straight forward

    Args:
        l1 (ListNode): Head node of first linked list
        l2 (ListNode): Head node of second linked list

    Returns:
        ListNode: The head node of result number in linked list format
    """
    carry = 0
    root = n = ListNode(0)
    while l1 or l2 or carry:
        v1 = v2 = 0
        if l1:
            v1 = l1.val
            l1 = l1.next
        if l2:
            v2 = l2.val
            l2 = l2.next
        carry, val = divmod(v1+v2+carry, 10)
        n.next = ListNode(val)
        n = n.next
    return root.next