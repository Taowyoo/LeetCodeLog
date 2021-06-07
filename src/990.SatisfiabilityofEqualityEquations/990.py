'''
File: 99.py
File Created: 2021-01-12 14:37:24 -08:00
Author: Taowyoo (caoyxsh@outlook.com)
Brief: https://leetcode.com/problems/satisfiability-of-equality-equations/
-----
Last Modified: 2021-01-12 14:37:35 -08:00
Modified By: Taowyoo (caoyxsh@outlook.com>)
-----
Copyright 2020 - 2021
'''

class Solution:
    """Union find
    """
    def equationsPossible(self, equations: List[str]) -> bool:
        parent = {}
        def find(x):
            if x not in parent:
                return x
            else:
                return find(parent[x])
        for i in equations:
            if i[1]=="=":
                a = i[0]
                b = i[-1]
                x = find(a)
                y = find(b)
                if x!=y:
                    parent[y] = x
        for i in equations:
            if i[1]=="!" and find(i[0])==find(i[-1]):
                return False
        return True